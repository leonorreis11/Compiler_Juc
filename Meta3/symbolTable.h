#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include "syntax_tree.h"


//Estrutura de cada elemento da tabela
typedef struct table_element {
    char *name;
    char *type;
    char *param_types;
    int num_param; //nº de parametros do método - +efiente em algumas partes do código
    int is_param;
    struct table_element *body;
    struct table_element *next_element;
    int line;
    int col;
    int alreadyUsed;
}table_element;

#endif

void check_program(table_element* lastElem, ast_tree* nodeAST);
void check_method_decl(ast_tree* nodeAST, table_element* lastElem, table_element* start);
int check_method_header(ast_tree* nodeAST, table_element* first);
void show_table(table_element* elem);   //Imprimir a tabela
table_element* insert_element(table_element* lastEl, table_element* newEl);
table_element* new_element(char *name, char *paramTypes, char *type, int params, int isVar);
int check_var_existence(table_element* st, char* name); //Verifica se o símbolo já existe
char* check_string_type(char* s);                                                      //Imprimir da forma pretendida o tipo (analisada)
char* myStrCat(char* s1, char* s2, bool free1, bool free2);
void check_semantic(ast_tree* nodeAST, table_element* lastElem, char* name, char* method_type, char * param_types);
bool verifie_two_member_op(char* type);
void check_two_member_op(ast_tree* nodeAST, table_element* last, char* method_name, char * method_type, char * param_types, bool logical);
char* check_var_type(ast_tree* nodeAST, table_element* last, char* method_name, char * method_type, char * param_types);
bool isLogicalOperator(char* type);
bool add_new_value(ast_tree* nodeAST);
bool verifie_one_member_op1(char* type);
bool verifie_one_member_op2(char* type);
void check_one_member_op(ast_tree* nodeAST, table_element* last, char* method_name, char* method_type, char * param_types, bool logical);
char* symbol_operator(char* string);
bool check_method_existence(table_element* st, char* name, char* type, char * param_types);
int check_inexact_arguments(char* paramTypes, ast_tree* nodeAST,table_element* last, char* funcName);
int check_num_param(ast_tree* nodeAST);
void check_call(ast_tree* nodeAST, table_element* last, char* method_name,char * method_type, char * param_types);
void check_field_decl(ast_tree* nodeAST, table_element* last, table_element* start);
void check_var_decl(ast_tree* nodeAST, table_element* last, table_element* start, int flag);
bool check_method_repetead(table_element* st, char* name, char* type, char * param_types);
