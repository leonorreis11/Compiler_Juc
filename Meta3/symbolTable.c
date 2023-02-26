#include "symbolTable.h"
#include "syntax_tree.h"

extern int erro_semantica;
extern int num_line;
extern int num_column;


table_element* global;
char * nome_tabela_global;  //Nome da tabela global
bool reserved=0; //Solução à pedreiro para: se vires outra vez o simbolo _ tens de dizer erro:already defined e não erro:reserved


table_element* new_element(char *name, char *paramTypes, char *type, int num_param, int is_param){
    table_element* newElement = (table_element *)malloc(sizeof(table_element));
    assert(newElement != NULL);
    newElement->name = name;
    newElement->type = type;
    newElement->param_types = paramTypes;
    newElement->num_param = num_param;
    newElement->is_param = is_param;
    newElement->body = NULL;
    newElement->next_element = NULL;
    newElement->line = 0;
    newElement->col = 0;
    newElement->alreadyUsed = 0;
    return newElement;
}

table_element* insert_element(table_element* lastEl, table_element* newEl){
    lastEl->next_element = newEl;
    return newEl;
}

void check_program(table_element* lastElem, ast_tree* nodeAST){
    if (strcmp(nodeAST->type, "Program") == 0) {
        nome_tabela_global = nodeAST->filho->token->value;
        if (nodeAST->filho!= NULL) {
            global = lastElem;
            check_program(lastElem, nodeAST->filho);
        }
    }
    else if (strcmp(nodeAST->type, "FieldDecl") == 0) {
        check_field_decl(nodeAST, lastElem, global);
    }
    else if (strcmp(nodeAST->type, "MethodDecl") == 0) {
        check_method_decl(nodeAST, lastElem, global);
    }
    while(lastElem->next_element)
        lastElem = lastElem->next_element;

    if (nodeAST->irmao != NULL) {
        check_program(lastElem, nodeAST->irmao);
    }
}


void check_method_decl(ast_tree* nodeAST, table_element* lastElem, table_element* start){
    //nome do método
    char* name = nodeAST->filho->filho->irmao->token->value;

    //tipo do método
    char* type;
    if(strcmp(nodeAST->filho->filho->irmao->irmao->type,"MethodParams") == 0)
        type = check_string_type(nodeAST->filho->filho->type);
    else
        type = check_string_type(nodeAST->filho->filho->irmao->type);

    //nº de argumentos
    int num_param = check_num_param(nodeAST->filho->filho);

    //argumentos do método
    char* param_types = "\0";
    ast_tree* temp = nodeAST->filho->filho->irmao->irmao->filho; //ParamDecl
    if(temp != NULL && temp->filho != NULL){
        while (temp != NULL && strcmp(temp->type, "ParamDecl") == 0) {
            if(temp->irmao!=NULL){
                param_types = myStrCat(param_types, check_string_type(temp->filho->type), false, false);
                param_types = myStrCat(param_types, ",", false, false);
            }
            else
                param_types = myStrCat(param_types, check_string_type(temp->filho->type), false, false);

            temp = temp->irmao;
        }
    }

    //Analisar method_header antes de ver se já existe:  "não ignorar, mesmo que seja redefinição de a(int,int)"
    temp = nodeAST->filho;
    table_element* new = new_element(name, "", type, num_param, 0);
    check_method_header(temp->filho, new);


    //Verificar se o método já existe
    if (check_method_existence(start, name, type, param_types)) {
        lastElem = insert_element(lastElem,new);
        temp = temp->irmao;
        table_element* tempElBody = new;
        while(tempElBody->body != NULL)
            tempElBody = tempElBody->body;
        if (temp->filho != NULL){
            check_var_decl(temp->filho, tempElBody, new, 1);
        }
    }
    else {
        erro_semantica = 1;
        printf("Line %d, col %d: Symbol %s(%s) already defined\n",nodeAST->filho->filho->irmao->token->num_linha, nodeAST->filho->filho->irmao->token->num_coluna, name, param_types);
    }
}

//devolve o nº de argumentos de um método
int check_num_param(ast_tree* nodeAST) {
    ast_tree* temp = nodeAST;
    int num_param=0;
    while (temp != NULL && strcmp(temp->type, "MethodParams") != 0) {
        temp = temp->irmao;
    }

    if(temp != NULL && temp->filho != NULL){
        temp = temp->filho;
        while (temp != NULL && strcmp(temp->type, "ParamDecl") == 0) {
            temp = temp->irmao;
            num_param++;
        }
    }
    return num_param;
}

int check_method_header(ast_tree* nodeAST, table_element* first) {
    int num_param=0;
    first->body = new_element("return", "", check_string_type(first->type), -1, 2);
    table_element* tempEl = first->body;

    ast_tree* temp = nodeAST;
    char* paramType = "";

    while (temp != NULL && strcmp(temp->type, "MethodParams") != 0) {
        temp = temp->irmao;
    }

    if(temp != NULL && temp->filho != NULL){
        temp = temp->filho;
        table_element* newEl;
        while (temp != NULL && strcmp(temp->type, "ParamDecl") == 0) {
            // atualizar paramTypes
            if(strlen(paramType) == 0)
                paramType = myStrCat(paramType, check_string_type(temp->filho->type), false, true);
            else{
                paramType = myStrCat(paramType, ",", true, false);
                paramType = myStrCat(paramType, check_string_type(temp->filho->type),true, true);
            }

            int aux = check_var_existence(first->body, temp->filho->irmao->token->value);
            if(aux==1){ //ok
                newEl = new_element(temp->filho->irmao->token->value, "", check_string_type(temp->filho->type), -2, 2);
                newEl->line = temp->filho->irmao->token->num_linha;
                newEl->col = temp->filho->irmao->token->num_coluna;
                tempEl->body = newEl;
                tempEl = newEl;
            }
            else if( aux == -1){ //reserved
                erro_semantica = 1;
                printf("Line %d, col %d: Symbol %s is reserved\n", temp->filho->irmao->token->num_linha, temp->filho->irmao->token->num_coluna, temp->filho->irmao->token->value);
            }
            else { //repetida
                erro_semantica = 1;
                printf("Line %d, col %d: Symbol %s already defined\n", temp->filho->irmao->token->num_linha, temp->filho->irmao->token->num_coluna, temp->filho->irmao->token->value);
            }

            temp = temp->irmao;
            num_param++;
        }

        if(strlen(paramType) != 0)
            first->param_types = paramType;
    }
    return num_param;
}

void check_field_decl(ast_tree* nodeAST, table_element* last, table_element* start){
    table_element* temp;
    bool control=1;
    table_element* aux = start->next_element;
    if(nodeAST != NULL){
        if(aux!=NULL){
            while(aux!=NULL && control){

                //verificar se já existe
                if (strcmp(aux->name, nodeAST->filho->irmao->token->value) == 0 && aux->is_param==1) {
                    control=0;
                    erro_semantica = 1;
                    printf("Line %d, col %d: Symbol %s already defined\n", nodeAST->filho->irmao->token->num_linha, nodeAST->filho->irmao->token->num_coluna, nodeAST->filho->irmao->token->value);
                }
                    //verificar se é reserved
                else if(strcmp(nodeAST->filho->irmao->token->value, "_") == 0){
                    control=0;
                    erro_semantica = 1;
                    printf("Line %d, col %d: Symbol %s is reserved\n", nodeAST->filho->irmao->token->num_linha, nodeAST->filho->irmao->token->num_coluna, nodeAST->filho->irmao->token->value);
                }
                aux=aux->next_element;
            }


            if (control) {
                temp = new_element(nodeAST->filho->irmao->token->value, "", check_string_type(nodeAST->filho->type), -1, 1);
                temp->line = nodeAST->filho->irmao->token->num_linha;
                temp->col = nodeAST->filho->irmao->token->num_coluna;
                last->next_element = temp;
            }
        }else{
            temp = new_element(nodeAST->filho->irmao->token->value, "", check_string_type(nodeAST->filho->type), -1, 1);
            temp->line = nodeAST->filho->irmao->token->num_linha;
            temp->col = nodeAST->filho->irmao->token->num_coluna;
            last->next_element = temp;
        }
    }
}

void check_var_decl(ast_tree* nodeAST, table_element* last, table_element* start, int flag){
    table_element* temp;
    if(nodeAST != NULL){
        if(strcmp(nodeAST->type, "VarDecl") == 0 ){
            int aux = check_var_existence(start, nodeAST->filho->irmao->token->value);
            if (aux==1) { //ok
                temp = new_element(nodeAST->filho->irmao->token->value, "", check_string_type(nodeAST->filho->type), -1, 1);
                temp->line = nodeAST->filho->irmao->token->num_linha;
                temp->col = nodeAST->filho->irmao->token->num_coluna;

                if(flag == 1){
                    last->body = temp;
                    last = temp;
                }

                else if(flag == 0){
                    insert_element(last, temp);
                }
            }
            else if(aux == -1){ //reserved
                erro_semantica = 1;
                printf("Line %d, col %d: Symbol %s is reserved\n", nodeAST->filho->irmao->token->num_linha, nodeAST->filho->irmao->token->num_coluna, nodeAST->filho->irmao->token->value);
            }
            else{ //repetida
                erro_semantica = 1;
                printf("Line %d, col %d: Symbol %s already defined\n", nodeAST->filho->irmao->token->num_linha, nodeAST->filho->irmao->token->num_coluna, nodeAST->filho->irmao->token->value);
            }
        }
    }
    if(nodeAST != NULL && flag == 1)
        check_var_decl(nodeAST->irmao, last, start, flag);
}


//1: variável não é repetida, 0: variavel repetida, -1: reserved
int check_var_existence(table_element* st, char* name) {
    /*if(strcmp(name, "_")==0 ){
        if(!reserved){
            reserved=1;
            return -1;
        }
        else
            return 0;
    }*/
    while (st != NULL) {
        if (strcmp(st->name, name) == 0){
            //é uma variável com o mesmo nome
            if(st->is_param)
                return 0;
        }else if(strcmp(name, "_")==0)
            return -1;

        st = st->body;
    }

    return 1;
}

//true -o método ainda não existe, false - o método já existe
bool check_method_existence(table_element* st, char* name, char* type, char * param_types) {
    while (st != NULL) {
        if (strcmp(st->name, name) == 0){
            //printf("<check_method_existence>st->name: %s st->type: %s st->paramTypes: %s\n", st->name, st->type,st->paramTypes );
            //é um método com o mesmo nome
            if(!st->is_param)
                if(strcmp(st->type, type) == 0) //é um método com o mesmo tipo
                    if(strcmp(st->param_types, param_types) == 0)  //é um método com o mesmo tipo de parâmetros
                        return false;
        }
        st = st->next_element;
    }
    return true;
}


char* myStrCat(char* s1, char* s2, bool free1, bool free2){
    static char* temps1;
    static char* temps2;
    temps1 = (char*)malloc((strlen(s1) + strlen(s2)) * sizeof(char));
    temps2 = (char*)malloc(strlen(s2) * sizeof(char));
    temps1 = strdup(s1);
    temps2 = strdup(s2);
    strcat(temps1, temps2);
    if (free1)
        free(s1);
    //free(temps2);
    if(free2)
        free(s2);
    return temps1;
}

//Imprimir da forma pretendida o tipo
char* check_string_type(char* s) {
    char* type = NULL;
    if (strcmp(s, "StringArray") == 0 || strcmp(s, "String[]") == 0) {
        type = (char*)calloc((strlen("String[]")+1), sizeof(char));
        strcpy(type, "String[]");
    }
    else if (strcmp(s, "Int") == 0 || strcmp(s, "int") == 0 ) {
        type = (char*)calloc((strlen("int")+1), sizeof(char));
        strcpy(type, "int");
    }
    else if (strcmp(s, "Double") == 0 || strcmp(s, "double") == 0) {
        type = (char*)calloc((strlen("double")+1), sizeof(char));
        strcpy(type, "double");
    }
    else if (strcmp(s, "Bool") == 0 || strcmp(s, "bool") == 0 || strcmp(s, "boolean") == 0) {
        type = (char*)calloc((strlen("boolean")+1), sizeof(char));
        strcpy(type, "boolean");
    }
    else if (strcmp(s, "Void" ) == 0 || strcmp(s, "void") == 0) {
        type = (char*)calloc((strlen("void")+1), sizeof(char));
        strcpy(type, "void");
    }
    else if (strcmp(s, "ParseArgs") == 0 ) {
        type = (char*)calloc((strlen("int")+1), sizeof(char));
        strcpy(type, "int");
    }
    return type;
}

//Imprimir a tabela - versão 11/12
void show_table(table_element* elem) {
    table_element* aux = elem;

    // Tabela Global
    printf("===== Class %s Symbol Table =====\n", nome_tabela_global);

    while (elem != NULL) {
        if (elem->is_param == 1) //variavel
            printf("%s\t\t%s\n", elem->name, elem->type);
        else if (elem->is_param == 0)  //método
            printf("%s\t(%s)\t%s\n", elem->name, elem->param_types, elem->type);
        elem = elem->next_element;
    }

    // Tabelas de funcoes
    while (aux != NULL) {
        if (aux->body != NULL) {

            printf("\n===== Method %s(%s) Symbol Table =====\n", aux->name, aux->param_types);

            table_element* method = aux->body;

            while (method != NULL) {
                if (method->is_param == 1 || method->is_param == 2) {
                    if (method->num_param!=-1)
                        printf("%s\t%s\t%s\tparam\n", method->name, method->param_types, method->type);
                    else
                        printf("%s\t\t%s\n", method->name, method->type);
                }

                method = method->body;
            }
        }
        aux = aux->next_element;
    }
    printf("\n");
}

void check_semantic(ast_tree* nodeAST, table_element* lastElem, char* name, char* method_type, char * param_types){
    //printf("%d --> Entrei aqui %s\n", nodeAST->token->num_linha, nodeAST->type);
    if(strcmp(nodeAST->type, "MethodDecl")==0){
        name = nodeAST->filho->filho->irmao->token->value; //nome do método

        if(strcmp(nodeAST->filho->filho->irmao->irmao->type,"MethodParams") == 0)
            method_type = check_string_type(nodeAST->filho->filho->type);
        else
            method_type = check_string_type(nodeAST->filho->filho->irmao->type);

        param_types = "\0";    //argumentos do método
        ast_tree* temp = nodeAST->filho->filho->irmao->irmao->filho; //ParamDecl
        if(temp != NULL && temp->filho != NULL){
            while (temp != NULL && strcmp(temp->type, "ParamDecl") == 0) {
                if(temp->irmao!=NULL){
                    param_types = myStrCat(param_types, check_string_type(temp->filho->type), false, false);
                    param_types = myStrCat(param_types, ",", false, false);
                }
                else
                    param_types = myStrCat(param_types, check_string_type(temp->filho->type), false, false);
                temp = temp->irmao;
            }
        }
        if(check_method_repetead(lastElem, name, method_type, param_types)){
            if (nodeAST->filho)
                check_semantic(nodeAST->filho, lastElem, name,method_type, param_types);
            if (nodeAST->irmao)
                check_semantic(nodeAST->irmao, lastElem, NULL, NULL, NULL);
        }else{
            if (nodeAST->irmao)
                check_semantic(nodeAST->irmao, lastElem, NULL, NULL, NULL);
        }
    }else{
        if (nodeAST->filho)
            check_semantic(nodeAST->filho, lastElem, name, method_type, param_types);
        if (nodeAST->irmao)
            check_semantic(nodeAST->irmao, lastElem, name,method_type, param_types);
    }

    if(verifie_two_member_op(nodeAST->type)){
        //printf("***isTwoMemberOperation**** Entrei aqui %s %d %d\n", nodeAST->type, nodeAST->num_linha,nodeAST->num_coluna);
        check_two_member_op(nodeAST, lastElem, name, method_type, param_types, false);         // Add div etc
    }
    else if(isLogicalOperator(nodeAST->type)){
        //printf("***isLogicalOperator**** Entrei aqui %s %d %d\n", nodeAST->type, nodeAST->num_linha,nodeAST->num_coluna);
        check_two_member_op(nodeAST, lastElem, name, method_type, param_types, true);          // Eq Lt Gt etc
    }

    else if(add_new_value(nodeAST)){                                          // se estiver só Intlit Reallit Boollit
        //printf("***isNewValue**** Entrei aqui %s\n", nodeAST->type);
    }
    else if(verifie_one_member_op1(nodeAST->type)){
        //printf("***isOneMemberOperationNonLogical**** Entrei aqui %s %d %d\n", nodeAST->type, nodeAST->token->num_linha,nodeAST->token->num_coluna);
        check_one_member_op(nodeAST, lastElem, name, method_type, param_types, false);
    }

    else if(verifie_one_member_op2(nodeAST->type)){
        //printf("***isOneMemberOperationLogical**** Entrei aqui %s %d %d\n", nodeAST->type, nodeAST->num_linha,nodeAST->num_coluna);
        check_one_member_op(nodeAST, lastElem, name, method_type, param_types, true);
    }
    else if(strcmp(nodeAST->type, "Call") == 0){
        //printf("***isOneMemberOperationNonLogical**** Entrei aqui %s %d %d\n", nodeAST->type, nodeAST->num_linha,nodeAST->num_coluna);
        check_call(nodeAST, lastElem, name,method_type, param_types);
    }
}

//true -o método ainda não existe, false - o método já existe
bool check_method_repetead(table_element* st, char* name, char* type, char * param_types) {
    while (st != NULL) {
        if (strcmp(st->name, name) == 0){
            //é um método com o mesmo nome
            if(!st->is_param)
                if(strcmp(st->type, type) == 0) //é um método com o mesmo tipo
                    if(strcmp(st->param_types, param_types) == 0) { //é um método com o mesmo tipo de parâmetros
                        if (st->alreadyUsed == 0) {
                            st->alreadyUsed = 1;
                            return true;
                        }
                        else {
                            return false;
                        }
                    }
        }
        st = st->next_element;
    }
    return false;
}

//Retorna true se for uma operação de add/sub/mul/div/mod/assign/parseArgs
bool verifie_two_member_op(char* type){
    if(strcmp(type, "Add") == 0)
        return true;
    else if(strcmp(type, "Sub") == 0)
        return true;
    else if(strcmp(type, "Mul") == 0)
        return true;
    else if(strcmp(type, "Div") == 0)
        return true;
    else if(strcmp(type, "Mod") == 0)
        return true;
    else if(strcmp(type, "Assign")==0)
        return true;
    else if(strcmp(type, "ParseArgs")==0)
        return true;
    else if(strcmp(type, "Lshift")==0)
        return true;
    else if(strcmp(type, "Rshift")==0)
        return true;
    else
        return false;
}

//method_name -> nome do método onde essa operação está
//1ºPasso: Descobrir o tipo de cada membro da operação; 2ºPasso: Verificar que tipo de operação é e aplicar os devidos critérios
void check_two_member_op(ast_tree* nodeAST, table_element* last, char* method_name, char * method_type, char * param_types, bool logical){
    //analisar 1º membro
    char* type1;
    if(strcmp(nodeAST->filho->type, "Id") == 0){
        type1 = check_var_type(nodeAST->filho, last, method_name, method_type, param_types);
        //printf("--> nodeAST->filho->value: %s nodeAST->filho->anot: %s\n", nodeAST->filho->token->value, nodeAST->filho->anot);
        nodeAST->filho->anot = type1;
        if(strcmp(type1,"undef") == 0){
            erro_semantica = 1;
            printf("Line %d, col %d: Cannot find symbol %s\n", nodeAST->filho->token->num_linha,nodeAST->filho->token->num_coluna,nodeAST->filho->token->value);
        }

    }else
        type1 = nodeAST->filho->anot;

    //analisar 2º membro
    char* type2;
    if(strcmp(nodeAST->filho->irmao->type, "Id") == 0){
        type2 = check_var_type(nodeAST->filho->irmao, last, method_name,method_type, param_types);
        //printf("--> nodeAST->filho->value: %s nodeAST->filho->anot: %s\n", nodeAST->filho->token->value, nodeAST->filho->anot);
        nodeAST->filho->irmao->anot= type2;
        if(strcmp(type2, "undef") == 0){
            erro_semantica = 1;
            printf("Line %d, col %d: Cannot find symbol %s\n", nodeAST->filho->irmao->token->num_linha, nodeAST->filho->irmao->token->num_coluna,nodeAST->filho->irmao->token->value);
        }
    }else
        type2 = nodeAST->filho->irmao->anot;
    //printf("-- method_name: %s method_type: %s param_types: %s (%d)nodeAST->type: %s type1: %s type2: %s\n",method_name, method_type, param_types, nodeAST->token->num_linha, nodeAST->type,type1, type2);

    //ParseArgs - exculsivamente type1 = String[] e type2[]=int
    if(strcmp(nodeAST->type, "ParseArgs") == 0){
        if(strcmp(type1, "String[]") == 0 && strcmp(type2, "int") == 0 )
            nodeAST->anot = type2;
        else{
            erro_semantica = 1;
            printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",nodeAST->token->num_linha, nodeAST->token->num_coluna, symbol_operator(nodeAST->type), type1, type2);
            nodeAST->anot = "int";
        }
    }
        //Operação em que os dois membros TÊM de ter o mesmo tipo
    else if(type1 != NULL && type2 != NULL && strcmp(type1, type2)==0){
        if(strcmp(type1, "undef") == 0 && strcmp(type2, "undef") == 0){
            erro_semantica = 1;
            printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",nodeAST->token->num_linha, nodeAST->token->num_coluna , symbol_operator(nodeAST->type), type1, type2);
            if(logical)
                nodeAST->anot = "boolean";
            else{
                nodeAST->anot = "undef";
                if(strcmp(nodeAST->type, "ParseArgs") == 0){ //ParseArgs é sempre int
                    nodeAST->anot = "int";
                    printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",nodeAST->token->num_linha, nodeAST->token->num_coluna, symbol_operator(nodeAST->type), type1, type1);
                }
            }
        }
        else{
            if(logical){
                if(strcmp(nodeAST->type,"And")==0 || strcmp(nodeAST->type,"Or")==0 ){
                    if(strcmp(type1, "int")==0 && strcmp(nodeAST->type,"Xor")==0)
                        nodeAST->anot = type1;
                    else if(strcmp(type1, "int")==0 && (strcmp(nodeAST->filho->token->value, "1")==0 || strcmp(nodeAST->filho->token->value, "0")==0) && (strcmp(nodeAST->filho->irmao->token->value, "1")==0 || strcmp(nodeAST->filho->irmao->token->value, "0")==0)){
                        nodeAST->anot = type1;
                    }
                    else if(strcmp(type1, "boolean")!=0) {
                        erro_semantica = 1;
                        printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",nodeAST->token->num_linha,nodeAST->token->num_coluna , symbol_operator(nodeAST->type), type1, type2);
                        nodeAST->anot="boolean"; //simpleTest (or de duas Strings é boolean)
                    }
                    else
                        nodeAST->anot = type1;
                }
                else if(strcmp(nodeAST->type,"Xor")==0){
                    if(strcmp(type1, "int")==0 && strcmp(nodeAST->type,"Xor")==0)
                        nodeAST->anot = type1;
                    else if(strcmp(type1, "int")==0 && (strcmp(nodeAST->filho->token->value, "1")==0 || strcmp(nodeAST->filho->token->value, "0")==0) && (strcmp(nodeAST->filho->irmao->token->value, "1")==0 || strcmp(nodeAST->filho->irmao->token->value, "0")==0)){
                        nodeAST->anot = type1;
                    }
                    else if(strcmp(type1, "boolean")!=0) {
                        erro_semantica = 1;
                        printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",nodeAST->token->num_linha,nodeAST->token->num_coluna , symbol_operator(nodeAST->type), type1, type2);
                        nodeAST->anot="undef"; //simpleTest (or de duas Strings é boolean)
                    }
                    else
                        nodeAST->anot = type1;
                }
                else if(strcmp(nodeAST->type,"Ge")==0 || strcmp(nodeAST->type,"Le")==0 || strcmp(nodeAST->type,"Gt")==0|| strcmp(nodeAST->type,"Lt")==0 ){
                    if(strcmp(type1, "int")!=0 && strcmp(type1, "double")!=0) {
                        erro_semantica = 1;
                        printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",nodeAST->token->num_linha,nodeAST->token->num_coluna, symbol_operator(nodeAST->type), type1, type2);
                    }
                    nodeAST->anot = "boolean";
                }
                else if(strcmp(nodeAST->type,"Eq")==0 && strcmp(type1, "String[]")==0){
                    erro_semantica = 1;
                    printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",nodeAST->token->num_linha,nodeAST->token->num_coluna, symbol_operator(nodeAST->type), type1, type2);
                    nodeAST->anot = "boolean";
                }
                else
                    nodeAST->anot = "boolean";
            }
            else{
                nodeAST->anot = type1;
                if(strcmp(type1, "boolean")==0 || strcmp(type1, "String[]")==0){    //só a operação assign é que aceita booleans
                    if (strcmp(nodeAST->type, "Assign")==0 && strcmp(type1, "boolean")==0 )
                        nodeAST->anot = type1;
                    else{
                        erro_semantica = 1;
                        printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",nodeAST->token->num_linha,nodeAST->token->num_coluna, symbol_operator(nodeAST->type), type1, type2);
                        nodeAST->anot = "undef";
                    }
                }
                else if(strcmp(nodeAST->type,"Lshift")==0 || strcmp(type1, "Rshift")==0){    //shifts só pode ser com dois int
                    if (strcmp(type1, "int")!=0){
                        erro_semantica = 1;
                        printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",nodeAST->token->num_linha,nodeAST->token->num_coluna, symbol_operator(nodeAST->type), type1, type2);
                        nodeAST->anot = "undef";
                    }else
                        nodeAST->anot = type1;

                }
            }
        }
        //acho que vai dar erro porque vou aceitar "undef"
        //Operação em que os dois membros NÃO têm de ter o mesmo tipo ->
    }else if(strcmp(nodeAST->type,"Eq")==0 ||strcmp(nodeAST->type,"Ne")==0 || strcmp(nodeAST->type,"Ge")==0 || strcmp(nodeAST->type,"Le")==0 || strcmp(nodeAST->type,"Gt")==0|| strcmp(nodeAST->type,"Lt")==0){
        if(strcmp(type1, "boolean") == 0 || strcmp(type2, "boolean") == 0 || strcmp(type1, "String[]") == 0 || strcmp(type2, "String[]") == 0 || strcmp(type1, "undef") == 0 || strcmp(type2, "undef") == 0 ){
            erro_semantica = 1;
            printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",nodeAST->token->num_linha,nodeAST->token->num_coluna, symbol_operator(nodeAST->type), type1, type2);
        }
        nodeAST->anot = "boolean";
        //Operação em que os dois membros NÃO têm de ter o mesmo tipo -> ParseArgs
    }
        //Operação em que os dois membros NÃO têm de ter o mesmo tipo -> Assign
    else if(strcmp(nodeAST->type, "Assign") == 0){
        if(strcmp(type1, "double") == 0 && strcmp(type2, "int") == 0){ //double = int é possível
            nodeAST->anot=type1;
        }
        else if(strcmp(type1, "int") == 0 && strcmp(type2, "double") == 0){
            erro_semantica = 1;
            printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",nodeAST->token->num_linha,nodeAST->token->num_coluna, symbol_operator(nodeAST->type), type1, type2);
            nodeAST->anot=type1;
        }
        else if(strcmp(type1, "undef") == 0 && strcmp(type2, "undef") != 0){
            erro_semantica = 1;
            printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",nodeAST->token->num_linha,nodeAST->token->num_coluna, symbol_operator(nodeAST->type), type1, type2);
            nodeAST->anot = type2;
        }else if(strcmp(type1, "undef") != 0 && strcmp(type2, "undef") == 0){
            erro_semantica = 1;
            printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",nodeAST->token->num_linha,nodeAST->token->num_coluna, symbol_operator(nodeAST->type), type1, type2);
            nodeAST->anot = type1;
        }else{
            erro_semantica = 1;
            printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",nodeAST->token->num_linha,nodeAST->token->num_coluna, symbol_operator(nodeAST->type), type1, type2);
            nodeAST->anot = type1;
        }
    }
        //Operação em que os dois membros NÃO têm de ter o mesmo tipo -> Add, Sub, Mod, Mul, Div
    else if(strcmp(nodeAST->type, "Add") == 0 || strcmp(nodeAST->type, "Sub") == 0 || strcmp(nodeAST->type, "Mod") == 0 || strcmp(nodeAST->type, "Mul") == 0 || strcmp(nodeAST->type, "Div") == 0){
        if( (strcmp(type1, "double") == 0 && strcmp(type2, "int") == 0) || (strcmp(type1, "int") == 0 && strcmp(type2, "double") == 0) )
            nodeAST->anot = "double";
        else{
            erro_semantica = 1;
            printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",nodeAST->token->num_linha,nodeAST->token->num_coluna,symbol_operator(nodeAST->type),type1, type2);
            nodeAST->anot = "undef";
        }
    }
    else{
        if(type1 == NULL)
            type1 = "none";
        if(type2 == NULL)
            type2 = "none";
        erro_semantica = 1;
        printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",nodeAST->token->num_linha,nodeAST->token->num_coluna, symbol_operator(nodeAST->type), type1, type2);
        if(logical)
            nodeAST->anot = "boolean";
        else
            nodeAST->anot = "undef";
    }
}


char* check_var_type(ast_tree* nodeAST, table_element* last, char* method_name, char * method_type, char * param_types){
    char* type = "undef";
    while(last != NULL){
        if(strcmp(last->name, nodeAST->token->value)==0 && last->is_param == 1){
            type = last->type;
            last->alreadyUsed = 1;
        }
        else if(strcmp(last->name, method_name) == 0 && strcmp(last->type, method_type) == 0 && strcmp(last->param_types, param_types) == 0 ){
            table_element* temp = last->body;
            while(temp != NULL ){
                if(temp->line < nodeAST->token->num_linha){
                    if(strcmp(temp->name, nodeAST->token->value)==0){
                        type = temp->type;
                        temp->alreadyUsed = 1;
                        return type;
                    }

                }
                else if(temp->line == nodeAST->token->num_linha && temp->col < nodeAST->token->num_coluna){
                    if(strcmp(temp->name, nodeAST->token->value)==0){
                        type = temp->type;
                        temp->alreadyUsed = 1;
                        return type;
                    }

                }
                temp = temp->body;
            }
        }
        if(last != NULL)
            last = last->next_element;
    }
    return type;
}

bool isLogicalOperator(char* type){
    if(strcmp(type, "Xor") == 0)
        return true;
    if(strcmp(type, "Or") == 0)
        return true;
    else if(strcmp(type, "Eq") == 0)
        return true;
    else if(strcmp(type, "Ne") == 0)
        return true;
    else if(strcmp(type, "Lt") == 0)
        return true;
    else if(strcmp(type, "Gt") == 0)
        return true;
    else if(strcmp(type, "Le") == 0)
        return true;
    else if(strcmp(type, "Ge") == 0)
        return true;
    else if(strcmp(type, "And") == 0)
        return true;
    else
        return false;
}

bool add_new_value(ast_tree* nodeAST){
    if(strcmp("RealLit", nodeAST->type)==0){
        char* aux  = nodeAST->token->value; //value
        char* new_str = malloc(strlen(aux) * sizeof(char)); //aux
        bool control_e=0, control_zeros=1;
        int i = 0, new_i=0;
        while(aux[i] != '\0')
        {
            if( (aux[i] >= '0' && aux[i]<='9') || aux[i]=='e' || aux[i]=='E' || aux[i]=='.' || aux[i]=='-')
            {
                if(aux[i]=='e' || aux[i]=='E')
                    control_e=1;
                if(aux[i]!='.' && aux[i]!='0' && !control_e)
                    control_zeros=0;
                new_str[new_i] = aux[i];
                new_i++;
            }

            i++;
        }
        if(!control_zeros){
            if(atof(new_str)== 0 || atof(new_str) >= 2147483648 || atof(new_str) < -2147483648 ){
                erro_semantica=1;
                printf("Line %d, col %d: Number %s out of bounds\n", nodeAST->token->num_linha, nodeAST->token->num_coluna,nodeAST->token->value);
            }
        }
        nodeAST->anot = "double";
        return true;
    }
    else if(strcmp("BoolLit", nodeAST->type)==0){
        nodeAST->anot = "boolean";
        return true;
    }
    else if(strcmp("DecLit", nodeAST->type)==0){
        char* aux  = nodeAST->token->value;

        char* new_str = malloc(strlen(aux) * sizeof(char));
        int i = 0, new_i=0;
        while(aux[i] != '\0')
        {
            if(aux[i] != '_')
            {
                new_str[new_i] = aux[i];
                new_i++;
            }

            i++;
        }
        if(atof(new_str) >= 2147483648 || atof(new_str) < -2147483648 ){
            erro_semantica = 1;
            printf("Line %d, col %d: Number %s out of bounds\n", nodeAST->token->num_linha,nodeAST->token->num_coluna,nodeAST->token->value);
        }nodeAST->anot = "int";
        return true;
    }
    else if(strcmp("StrLit", nodeAST->type)==0){
        nodeAST->anot = "String";
        return true;
    }
    return false;
}

bool verifie_one_member_op1(char* type){
    if(strcmp(type, "Minus") == 0)
        return true;
    else if(strcmp(type, "Plus") == 0)
        return true;
    else if(strcmp(type, "Print") == 0)
        return true;
    else if(strcmp(type, "Length") == 0)
        return true;
    else if(strcmp(type, "Return") == 0)
        return true;
    else
        return false;
}

bool verifie_one_member_op2(char* type){
    if(strcmp(type, "Not") == 0)
        return true;
    if(strcmp(type, "If") == 0)
        return true;
    else if(strcmp(type, "For") == 0 )
        return true;
    else if(strcmp(type, "While") == 0)
        return true;
    else
        return false;
}

//devolve -1 se o método não é coincidente; devolve num_non_match- nº de parametros que não são do mesmo tipo
int check_inexact_arguments(char* paramTypes, ast_tree* nodeAST,table_element* last, char* method_name){
    ast_tree* temp=nodeAST;
    static char* paramTypes_copy;   //string que vai ser partida ("int", "String[]", etc)
    paramTypes_copy = (char*)malloc(strlen(paramTypes) * sizeof(char));
    strcpy(paramTypes_copy, paramTypes);
    const char delim[2] = ",";
    char *ptr = strtok(paramTypes_copy, delim);
    char* type_aux;
    table_element* lastCopy = last; //utilizado para determinar o tipo das variáveis usadas dentro do call
    int num_non_match=0;

    while(ptr != NULL && temp!=NULL)
    {
        //os tipos diferem
        if(strcmp(ptr, temp->anot)!=0){
            if(((strcmp(ptr, "double")==0 && strcmp(temp->anot, "int")==0)))
                num_non_match++;
            else
                return -1;
        }

        ptr = strtok(NULL, delim);
        temp = temp->irmao;
    }
    return num_non_match;
}

void check_call(ast_tree* nodeAST, table_element* last, char* method_name,char * method_type, char * param_types){
    int exists = 0;
    char* type = "undef";
    char* params = "\0"; //usado para imprimir o erro
    bool control=1;
    table_element* lastCopy = last;
    table_element* lastCopy2 = last;

    //contar nº de parametros e anotar ids
    int num_params=0;
    char* type_aux;
    ast_tree* temp=nodeAST->filho->irmao;
    while(temp!=NULL){
        if(strcmp(temp->type, "Id") == 0){
            type_aux = check_var_type(temp, lastCopy, method_name, method_type, param_types);
            temp->anot = type_aux;
            if(strcmp(type_aux,"undef")==0){
                printf("Line %d, col %d: Cannot find symbol %s\n", temp->token->num_linha,temp->token->num_coluna,temp->token->value);
                erro_semantica = 1;
                control=0;
            }
        }
        if(temp->irmao!=NULL){
            params = myStrCat(params, temp->anot, false, false);
            params = myStrCat(params, ",", false, false);
        }
        else
            params = myStrCat(params, temp->anot, false, false);
        num_params++;
        temp = temp->irmao;
    }

    //Exact match
    while(last != NULL && exists!=1 && control){
        //encontrada função com o mesmo nome e mesmos argumentos
        if(strcmp(last->name, nodeAST->filho->token->value)==0 && strcmp(last->param_types, params)==0 ) {
            ast_tree* temp=nodeAST->filho->irmao;
            exists = 1;
            type = last->type;
            char* aux = "(";
            aux = myStrCat(aux, params, false, false);
            aux = myStrCat(aux, ")", true, false);
            nodeAST->filho->anot = aux;
        }

        last = last->next_element;
    }

    //Inexact match
    int aux_non_match;
    char* aux_type = "undef";
    char* aux_params = "\0"; //usado para imprimir o erro
    if(exists==0 && control){
        while(lastCopy2 != NULL){
            //encontrada função com o mesmo nome e mesmo nº de argumentos
            if(strcmp(lastCopy2->name, nodeAST->filho->token->value)==0 && lastCopy2->num_param == num_params) {
                ast_tree* temp=nodeAST->filho->irmao;
                aux_non_match = check_inexact_arguments(lastCopy2->param_types ,temp, lastCopy, method_name);
                if(aux_non_match!=-1){
                    exists=exists+1;
                    aux_type = lastCopy2->type;
                    aux_params = lastCopy2->param_types;
                }
            }

            lastCopy2 = lastCopy2->next_element;
        }

        if(exists==1){
            type=aux_type;
            char* aux = "(";
            aux = myStrCat(aux, aux_params, false, false);
            aux = myStrCat(aux, ")", true, false);
            nodeAST->filho->anot = aux;
        }
    }
    if(exists>1){
        nodeAST->filho->anot = "undef";
        printf("Line %d, col %d: Reference to method %s(%s) is ambiguous\n", nodeAST->filho->token->num_linha,nodeAST->filho->token->num_coluna,nodeAST->filho->token->value,params);
        erro_semantica = 1;
        nodeAST->anot = "undef";
    }
    else if(exists!=1){
        nodeAST->filho->anot = "undef";
        printf("Line %d, col %d: Cannot find symbol %s(%s)\n", nodeAST->filho->token->num_linha,nodeAST->filho->token->num_coluna,nodeAST->filho->token->value,params);
        erro_semantica = 1;
        nodeAST->anot = "undef";
    }else if(strcmp(type, "none")!= 0)
        nodeAST->anot= type;
}

//While etc.
void check_one_member_op(ast_tree* nodeAST, table_element* last, char* method_name, char* method_type, char * param_types, bool logical){
    char* type;
    if(nodeAST->filho == NULL)
        type = "none";
    else if(strcmp(nodeAST->filho->type, "Id") == 0){
        type = check_var_type(nodeAST->filho, last, method_name, method_type, param_types);
        nodeAST->filho->anot = type;
        if(strcmp(type,"undef")==0){
            printf("Line %d, col %d: Cannot find symbol %s\n", nodeAST->filho->token->num_linha,nodeAST->filho->token->num_coluna,nodeAST->filho->token->value);
            erro_semantica = 1;
        }
    }else{
        type = nodeAST->filho->anot;
    }

    //printf("---checkOneMemberOperation nodeAST->type: %s type: %s\n",nodeAST->type, type);
    if( type != NULL && strcmp(nodeAST->type, "Length")==0 ){   //Length só suposta String[] mas é sempre anot->int
        if(strcmp(type, "String[]") != 0){
            printf("Line %d, col %d: Operator %s cannot be applied to type %s\n",nodeAST->token->num_linha, nodeAST->token->num_coluna, symbol_operator(nodeAST->type), type);
            erro_semantica = 1; //coluna a funcionar
            nodeAST->anot="int";
        }else
            nodeAST->anot="int";

    }
    else if(type != NULL && strcmp(type, "undef") != 0){
        if(logical){
            //if(strcmp(type, "boolean") == 0){
            //if(strcmp(nodeAST->type, "If") != 0 && strcmp(nodeAST->type, "For") != 0)
            //nodeAST->anot = "boolean";
            //}
            if(strcmp(type, "boolean") != 0){
                if(strcmp(nodeAST->type, "If") == 0 || strcmp(nodeAST->type, "For") == 0 || strcmp(nodeAST->type, "While") == 0){
                    ast_tree* aux_node = nodeAST;
                    if(aux_node->filho!=NULL)
                    {
                        aux_node=aux_node->filho;
                        if(strcmp(aux_node->type, "Call")==0){
                            while(aux_node->filho!=NULL){
                                aux_node=aux_node->filho;
                            }
                        }
                    }
                    printf("Line %d, col %d: Incompatible type %s in %s statement\n", aux_node->token->num_linha, aux_node->token->num_coluna, type, symbol_operator(nodeAST->type));
                    erro_semantica = 1;
                }
                else{
                    printf("Line %d, col %d: Operator %s cannot be applied to type %s\n",nodeAST->token->num_linha, nodeAST->token->num_coluna, symbol_operator(nodeAST->type), type);
                    nodeAST->anot = "boolean";
                    erro_semantica = 1;
                }
            }/*else{
                nodeAST->anot = "boolean";
            }*/ //Comentado porque o teste CallError.java diz que o if não pode ser anotado

            else if(strcmp(nodeAST->type, "Not") == 0){ //exemplo: !true - boolean_xor_,java
                nodeAST->anot=type;
            }
        }
        else if(strcmp(nodeAST->type, "Return") == 0){
            if(strcmp(method_type, type)!=0 ||  strcmp(method_type, "void")==0 ){
                if(!((strcmp(method_type, "void")==0 && strcmp(type, "none")==0) || (strcmp(method_type, "double")==0 && strcmp(type, "int")==0))){
                    if(strcmp(type,"none")==0)
                        type="void";
                    erro_semantica = 1;
                    ast_tree* aux_node = nodeAST;
                    if(aux_node->filho!=NULL)
                    {
                        aux_node=aux_node->filho;
                        if(strcmp(aux_node->type, "Call")==0){
                            while(aux_node->filho!=NULL){
                                aux_node=aux_node->filho;
                            }
                        }
                    }
                    printf("Line %d, col %d: Incompatible type %s in return statement\n",aux_node->token->num_linha, aux_node->token->num_coluna, type);
                    erro_semantica = 1;
                }
            }
        }
        else if(strcmp(nodeAST->type, "Print")==0 && (strcmp(type, "void") == 0 || strcmp(type, "String[]") == 0) ){
            ast_tree* aux_node = nodeAST;
            if(aux_node->filho!=NULL)
            {
                aux_node=aux_node->filho;
                if(strcmp(aux_node->type, "Call")==0){
                    while(aux_node->filho!=NULL){
                        aux_node=aux_node->filho;
                    }
                }
            }
            printf("Line %d, col %d: Incompatible type %s in %s statement\n", aux_node->token->num_linha, aux_node->token->num_coluna, type, symbol_operator(nodeAST->type));
            erro_semantica = 1;
        }
        else if( strcmp(nodeAST->type, "Length")==0 ){
            if(strcmp(type, "String[]") != 0){
                printf("Line %d, col %d: Operator %s cannot be applied to type %s\n",nodeAST->token->num_linha, nodeAST->token->num_coluna, symbol_operator(nodeAST->type), type);
                erro_semantica = 1;
                nodeAST->anot="int";
            }else
                nodeAST->anot="int";

        }
        else if(strcmp(nodeAST->type, "Plus") == 0 || strcmp(nodeAST->type, "Minus") == 0){
            if(strcmp(type, "boolean") == 0){
                printf("Line %d, col %d: Operator %s cannot be applied to type %s\n",nodeAST->token->num_linha, nodeAST->token->num_coluna, symbol_operator(nodeAST->type), type);
                nodeAST->anot="undef";
                erro_semantica = 1;
            }
            else
                nodeAST->anot=type;

        }
    }
    else{
        if(strcmp(nodeAST->type, "Return") == 0 ){
            if(strcmp(type,"none")==0)
                type="void";
            ast_tree* aux_node = nodeAST;
            if(aux_node->filho!=NULL)
            {
                aux_node=aux_node->filho;
                if(strcmp(aux_node->type, "Call")==0){
                    while(aux_node->filho!=NULL){
                        aux_node=aux_node->filho;
                    }
                }
            }
            printf("Line %d, col %d: Incompatible type %s in %s statement\n", aux_node->token->num_linha, aux_node->token->num_coluna, type, symbol_operator(nodeAST->type));
            erro_semantica = 1;
        }
        else if(strcmp(nodeAST->type, "Print")==0 && strcmp(type, "String[]") != 0){
            ast_tree* aux_node = nodeAST;
            if(aux_node->filho!=NULL)
            {
                aux_node=aux_node->filho;
                if(strcmp(aux_node->type, "Call")==0){
                    while(aux_node->filho!=NULL){
                        aux_node=aux_node->filho;
                    }
                }
            }
            printf("Line %d, col %d: Incompatible type %s in %s statement\n", aux_node->token->num_linha, aux_node->token->num_coluna, type, symbol_operator(nodeAST->type));
            erro_semantica = 1;
        }
        else if((strcmp(nodeAST->type, "If") == 0 || strcmp(nodeAST->type, "For") == 0 || strcmp(nodeAST->type, "While") == 0)  && type != NULL){
            ast_tree* aux_node = nodeAST;
            if(aux_node->filho!=NULL)
            {
                aux_node=aux_node->filho;
                if(strcmp(aux_node->type, "Call")==0){
                    while(aux_node->filho!=NULL){
                        aux_node=aux_node->filho;
                    }
                }
            }
            printf("Line %d, col %d: Incompatible type %s in %s statement\n", aux_node->token->num_linha, aux_node->token->num_coluna, type, symbol_operator(nodeAST->type));
            erro_semantica = 1;
        }
        else if(strcmp(nodeAST->type, "Print")!=0 && strcmp(nodeAST->type, "If") != 0 && strcmp(nodeAST->type, "For") != 0){
            printf("Line %d, col %d: Operator %s cannot be applied to type %s\n",nodeAST->token->num_linha, nodeAST->token->num_coluna, symbol_operator(nodeAST->type), type);
            erro_semantica = 1;
        }
    }
}

char* symbol_operator(char* string){
    if(strcmp(string, "Assign")==0)
        return "=";
    if(strcmp(string, "Length")==0)
        return ".length";
    else if(strcmp(string, "Add")==0)
        return "+";
    else if(strcmp(string, "Xor")==0)
        return "^";
    else if(strcmp(string, "Sub")==0)
        return "-";
    else if(strcmp(string, "Mul")==0)
        return "*";
    else if(strcmp(string, "Div")==0)
        return "/";
    else if(strcmp(string, "Mod")==0)
        return "%";
    else if(strcmp(string, "And")==0)
        return "&&";
    else if(strcmp(string, "Or")==0)
        return "||";
    else if(strcmp(string, "Ne")==0)
        return "!=";
    else if(strcmp(string, "Lt")==0)
        return "<";
    else if(strcmp(string, "Gt")==0)
        return ">";
    else if(strcmp(string, "Ge")==0)
        return ">=";
    else if(strcmp(string, "Le")==0)
        return "<=";
    else if(strcmp(string, "Return")==0)
        return "return";
    else if(strcmp(string, "For")==0)
        return "for";
    else if(strcmp(string, "If")==0)
        return "if";
    else if(strcmp(string, "While")==0)
        return "while";
    else if(strcmp(string, "ParseArgs") == 0)
        return "Integer.parseInt";
    else if(strcmp(string, "Not") == 0)
        return "!";
    else if(strcmp(string, "Print") == 0)
        return "System.out.print";
    else if(strcmp(string, "Plus") == 0)
        return "+";
    else if(strcmp(string, "Minus") == 0)
        return "-";
    else if(strcmp(string, "Eq") == 0)
        return "==";
    else if(strcmp(string, "Lshift") == 0)
        return "<<";
    else if(strcmp(string, "Rshift") == 0)
        return ">>";

    else
        return NULL;
}

