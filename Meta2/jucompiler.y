
%{
/* Ricardo Santiago 2020219352
   Leonor Reis 2019210146
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include "syntax_tree.h"


ast_tree* root;
ast_tree* temp;
ast_tree* temp2;
ast_tree* temp3;



 
 int yylex(void);
 extern void yyerror(const char*);


  
%}

%union{
    char* id;
    struct node* node;
}

%token <id> ID
%token <id> INTLIT
%token <id> REALLIT
%token <id> BOOLLIT
%token <id> STRLIT
%token AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE
%token RPAR RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR CLASS DOTLENGTH ELSE IF PRINT PARSEINT PUBLIC
%token RETURN STATIC STRING VOID WHILE INT DOUBLE BOOL RESERVED

%type <node> Program Program1 MethodDecl FieldDecl FieldDeclRep Type MethodHeader FormalParams FormalParams1
%type <node> MethodBody MethodBody1 VarDecl VarDeclRep Statement Statement1
%type <node> MethodInvocation MethodInvocation1 Assignment ParseArgs Expr Expr1



%right ASSIGN
%left OR
%left AND
%left XOR
%left EQ NE 
%left GE GT LE LT
%left RSHIFT LSHIFT
%left PLUS MINUS
%left STAR DIV MOD
%right NOT
%left LPAR RPAR LSQ RSQ

%right ELSE



%%

Program:    CLASS ID LBRACE Program1 RBRACE         { $$=root= create_node("","Program");
                                                        temp =create_node($2,"Id");
                                                        adicionar_filho(root,temp);
                                                        adicionar_filho(root,$4);
                                                        }
                                                        
                                                      
;

Program1:   MethodDecl Program1                     {$$ = $1; adicionar_irmao($$,$2); }
| FieldDecl Program1                                 {if($1 != NULL){
                                                        $$ = $1; 
                                                        adicionar_irmao($$,$2);
                                                       }else{
                                                        $$ =$2;
                                                        }
                                                    }
| SEMICOLON Program1                                   {$$ = $2;}
|                                                   {$$ = NULL;}
;
MethodDecl:  PUBLIC STATIC MethodHeader MethodBody  {$$ = create_node("","MethodDecl");
                                                     adicionar_filho($$,$3);
                                                        adicionar_filho($$,$4);
                                                        
                                                       }
;

FieldDecl:   PUBLIC STATIC Type ID FieldDeclRep SEMICOLON {$$ = create_node("","FieldDecl");
                                                                adicionar_filho($$,$3);
                                                                adicionar_filho($$,create_node($4,"Id"));
                                                                if($5 != NULL){
                                                                    temp = $5;   
                                                                        while(temp!=NULL){
                                                                            
                                                                            temp2= create_node("","FieldDecl");
                                                                             temp3=create_node($3->value,$3->type); 
                                                                              adicionar_filho(temp2,temp3);
                                                                              adicionar_filho(temp2,create_node(temp->value,"Id"));
                                                                              adicionar_irmao($$,temp2);

                                                                             temp=temp->irmao;
                                                                       }
                                                                }
                                                           
                                                            }
   | error SEMICOLON                                    {$$ = NULL; }
   ;

FieldDeclRep: COMMA ID FieldDeclRep                         {$$ =temp=create_node($2,"Id");
                                                    adicionar_irmao($$,$3);
                                                   }  
|                                                       {$$= NULL;}
;

Type:       BOOL                                        {$$ = create_node("","Bool");}
| INT                                                    {$$ =create_node("","Int");}
| DOUBLE                                                {$$ =create_node("","Double");}
;

MethodHeader:    Type  ID LPAR FormalParams  RPAR       {$$ = create_node("","MethodHeader");
                                                          adicionar_filho($$,$1);
                                                          temp =create_node($2,"Id");
                                                          adicionar_filho($$,temp);
                                                            temp2= create_node("","MethodParams");
                                                            adicionar_filho($$,temp2);
                                                             adicionar_filho(temp2,$4);
                                                           
                                                            }
| VOID ID LPAR FormalParams  RPAR                       {$$ = create_node("","MethodHeader");
                                                        temp=create_node("","Void");
                                                        adicionar_filho($$,temp);
                                                        adicionar_filho($$,create_node($2,"Id"));
                                                        temp2 = create_node("","MethodParams");
                                                        adicionar_filho($$,temp2);
                                                        adicionar_filho(temp2,$4);
                                                        
                                                        }
| Type  ID LPAR RPAR                                    {$$ = create_node("","MethodHeader");
                                                         adicionar_filho($$,$1);
                                                         adicionar_filho($$,create_node($2,"Id"));
                                                         temp2 = create_node("","MethodParams");
                                                        adicionar_filho($$,temp2);
                                                         
                                                         }
| VOID ID LPAR RPAR                                     {$$ = create_node("","MethodHeader");
                                                            temp=create_node("","Void");
                                                            adicionar_filho($$,temp);
                                                            adicionar_filho($$,create_node($2,"Id"));
                                                            temp2 = create_node("","MethodParams");
                                                        adicionar_filho($$,temp2);
                                                            }
;

FormalParams:    Type ID FormalParams1                  {$$= create_node("","ParamDecl");            
                                                            adicionar_filho($$,$1);
                                                            adicionar_filho($$,create_node($2,"Id"));
                                                            adicionar_irmao($$,$3);
                                                             } 
| STRING LSQ RSQ ID                                      {$$ = create_node("","ParamDecl");
                                                            temp=create_node("","StringArray");
                                                            adicionar_filho($$,temp);
                                                             adicionar_filho($$,create_node($4,"Id"));
                                                             }
;

FormalParams1:  COMMA Type ID FormalParams1             {$$ = create_node("","ParamDecl");
                                                            adicionar_filho($$,$2);
                                                            adicionar_filho($$,create_node($3,"Id"));
                                                            adicionar_irmao($$,$4);
                                                           
                                                            }
|                                                       {$$= NULL;}
;

MethodBody: LBRACE MethodBody1 RBRACE               {$$ = create_node("","MethodBody");
                                                    adicionar_filho($$,$2);
                                                  
                                                    }
;

MethodBody1: Statement MethodBody1                  { 
                                                    if($1 != NULL){
                                                    $$=$1;
                                                    adicionar_irmao($$,$2);
                                                    }else{
                                                    $$=$2;
                                                    }     
                                                    }
| VarDecl MethodBody1                               {$$=$1;adicionar_irmao($$,$2);}
|                                                   {$$ = NULL;}
;

VarDecl: Type ID VarDeclRep SEMICOLON               {$$ = create_node("","VarDecl");
                                                        adicionar_filho($$,$1);
                                                        adicionar_filho($$,create_node($2,"Id"));
                                                       
                                                        if($3 != NULL){
                                                            temp=$3;
                                                            while(temp!=NULL){
                                                                temp2= create_node("","VarDecl"); 
                                                                temp3=create_node($1->value,$1->type); 
                                                                adicionar_filho(temp2,temp3);
                                                                adicionar_filho(temp2,create_node(temp->value,"Id"));
                                                                adicionar_irmao($$,temp2);
                                                                temp=temp->irmao;
                                                            }
                                                        }
                                                        }
;

VarDeclRep: COMMA ID VarDeclRep                         {$$ = temp = create_node($2,"Id");                                                       
                                                                adicionar_irmao($$,$3);
                                                              
                                                                }   
|                                                       {$$= NULL;}
;

Statement: LBRACE Statement1 RBRACE                {   
                                                        if ( block_count($2) > 1 ) {
														temp = create_node("", "Block");
														$$ = temp;
														adicionar_filho(temp, $2);
														}
														else {
														$$ = $2;
															}
                                                           
                                                            }
| IF LPAR Expr RPAR Statement ELSE Statement {
                                                    $$ = create_node("", "If");
												adicionar_filho($$,$3);
												temp = create_node( "", "Block");
												if (block_count($5) == 1 && $5 != NULL) {
													adicionar_filho($$, $5);
													if (block_count($7) == 1 && $7 != NULL) {
														adicionar_filho($$, $7);
													}
													else {
														adicionar_filho($$, temp);
														adicionar_filho(temp, $7);
													}
												}
												else {
														adicionar_filho($$, temp);
														adicionar_filho(temp, $5);
														if (block_count($7) == 1 && $7 != NULL) {
															adicionar_filho($$, $7);
															}
														else {
														    temp2 = create_node("", "Block");
															adicionar_filho($$, temp2);
															adicionar_filho(temp2, $7);
															}
													}
                                                  }
| IF LPAR Expr RPAR Statement                 { 
                                                $$=create_node("","If");
                                                adicionar_filho($$,$3);
                                                temp = create_node("","Block");
                                                if($5 != NULL && block_count($5) == 1 ){
                                                adicionar_filho($$,$5); 
                                                adicionar_filho($$, temp);
                                                }
                                                else{
                                                adicionar_filho($$,temp);
                                                adicionar_filho(temp,$5);
                                                adicionar_filho($$,create_node("","Block"));
                                                }
                                              
                                              }
| WHILE LPAR Expr RPAR Statement             { 
                                                $$ = create_node("", "While");
												adicionar_filho($$, $3);
												if (block_count($5) < 2 && $5 != NULL) {
													adicionar_filho($$, $5);
												}
												else {
													temp = create_node("", "Block");
													adicionar_filho($$, temp);
													adicionar_filho(temp, $5);
												}
                                                
                                                }


| RETURN SEMICOLON      {$$= create_node("","Return");}
| RETURN Expr SEMICOLON      {$$= create_node("","Return");
                                adicionar_filho($$,$2);}
| MethodInvocation SEMICOLON     {$$=$1;}
| Assignment SEMICOLON   {$$=$1;}
| ParseArgs SEMICOLON   {$$=$1;}
| SEMICOLON {$$=NULL;}
| PRINT LPAR Expr RPAR SEMICOLON     {$$=create_node("","Print");
                                        adicionar_filho($$,$3);
                                          }
| PRINT LPAR STRLIT RPAR SEMICOLON  {$$ = create_node("","Print");
                                        temp = create_node($3,"StrLit");
                                        adicionar_filho($$,temp);
                                                                  
                                        }   
| error SEMICOLON       {$$ = NULL;}

;

Statement1:	Statement Statement1       {   
                                        if ($1 != NULL) {
										$$ = $1;
									    adicionar_irmao($$, $2);
									    }
										else {
										$$ = $2;
										}
                                      }
|                                {$$ = NULL;}
;

    
MethodInvocation: ID LPAR RPAR                   {$$=create_node("","Call");
                                                    temp=create_node($1,"Id");
                                                     adicionar_filho($$,temp); 
                                                     }

                | ID LPAR Expr MethodInvocation1 RPAR {$$=create_node("","Call");
                                                    temp=create_node($1,"Id");
                                                     adicionar_filho($$,temp);
                                                     adicionar_filho($$,$3); 
                                                    adicionar_filho($$,$4);
                                                     }
                | ID LPAR error RPAR    {$$=NULL;}



MethodInvocation1: COMMA Expr MethodInvocation1 {if($2!=NULL){
                                            $$=$2;
                                            adicionar_irmao($$,$3);
                                            }else{
                                                $$=$2;
                                            }
                                           }
            |                         {$$=NULL;}
            ;


Assignment: ID ASSIGN Expr                                {$$ = create_node("","Assign");
                                                                temp=create_node($1,"Id");
                                                                adicionar_filho($$,temp);
                                                                adicionar_filho($$,$3);
                                                              }
;

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR               {$$ = create_node("","ParseArgs");
                                                                temp=create_node($3,"Id");
                                                                adicionar_filho($$,temp);
                                                                adicionar_filho($$,$5);
                                                                }
|   PARSEINT LPAR error RPAR                                {$$ = NULL;}
;

Expr: Assignment            {$$=$1;}
| Expr1                 {$$=$1;}
;

Expr1:     Expr1 PLUS Expr1            {$$ = create_node("","Add");
                                        adicionar_filho($$,$1);
                                        adicionar_filho($$,$3);
                                      }
| Expr1 MINUS Expr1                    {$$ = create_node("","Sub");
                                        adicionar_filho($$,$1);
                                        adicionar_filho($$,$3);
                                     }
| Expr1 STAR Expr1                      {$$ = create_node("","Mul");
                                            adicionar_filho($$,$1);
                                            adicionar_filho($$,$3);
                                        ;}
| Expr1 DIV Expr1                          {$$ = create_node("","Div");
                                                    adicionar_filho($$,$1);
                                                adicionar_filho($$,$3);
                                           }
| Expr1 MOD Expr1                              {$$ = create_node("","Mod");
                                                adicionar_filho($$,$1);
                                                adicionar_filho($$,$3);
                                            }
| Expr1 AND Expr1                                  {$$ = create_node("","And");
                                                    adicionar_filho($$,$1);
                                                    adicionar_filho($$,$3);}
                                             
                                               
| Expr1 OR  Expr1                                      {$$ = create_node("","Or");
                                                        adicionar_filho($$,$1);
                                                        adicionar_filho($$,$3);
                                                  }
| Expr1 XOR Expr1                                       {$$ = create_node("","Xor");
                                                        adicionar_filho($$,$1);
                                                            adicionar_filho($$,$3);
                                                        }
| Expr1 LSHIFT Expr1                                       {$$ = create_node("","Lshift");
                                                            adicionar_filho($$,$1);
                                                                adicionar_filho($$,$3);
                                                            }
| Expr1 RSHIFT Expr1                                          {$$ = create_node("","Rshift");
                                                            adicionar_filho($$,$1);
                                                                adicionar_filho($$,$3);
                                                             }
| Expr1 EQ Expr1                                                {$$ = create_node("","Eq");
                                                        adicionar_filho($$,$1);
                                                    adicionar_filho($$,$3);
                                                  }
| Expr1 GE Expr1                                                  {$$ = create_node("","Ge");
                                                                adicionar_filho($$,$1);
                                                            adicionar_filho($$,$3);
                                                           }
| Expr1 GT Expr1                                              {$$ = create_node("","Gt");
                                                             adicionar_filho($$,$1);
                                                            adicionar_filho($$,$3);
                                                          }
| Expr1 LE Expr1                                              {$$ = create_node("","Le");
                                                                        adicionar_filho($$,$1);
                                                                        adicionar_filho($$,$3);
                                                                   }
| Expr1 LT Expr1                                                  {$$ = create_node("","Lt");
                                                                adicionar_filho($$,$1);
                                                                adicionar_filho($$,$3);}
| Expr1 NE Expr1                                                  {$$ = create_node("","Ne");
                                                            adicionar_filho($$,$1);
                                                                adicionar_filho($$,$3);
                                                                }
| MINUS Expr1   %prec NOT                                    {$$ = create_node("","Minus");
                                                                adicionar_filho($$,$2);
                                                               }
| NOT Expr1                                            {$$ = create_node("","Not");
                                                                    adicionar_filho($$,$2);
                                                                    }
| PLUS Expr1      %prec NOT                                         {$$ = create_node("","Plus");
                                                                            adicionar_filho($$,$2);
                                                                            }
| LPAR Expr RPAR                                                    {$$=$2;}
| MethodInvocation                                                  {$$=$1;}
| ParseArgs                                                            {$$=$1;}
| ID                                                                      {$$ = create_node($1,"Id");}
| ID DOTLENGTH                                                              {$$ = create_node("","Length");
                                                                                adicionar_filho($$,create_node($1,"Id"));
                                                                                } 
| INTLIT                                                                   {$$ = create_node($1,"DecLit");}
| REALLIT                                                                   {$$ = create_node($1,"RealLit");}
| BOOLLIT                                                                      {$$ = create_node($1,"BoolLit");}
| LPAR error RPAR                       {$$ = NULL;}
;


%%