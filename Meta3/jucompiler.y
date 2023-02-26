
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
extern int num_line;
extern int num_column;

  
%}


%token <token> ID
%token <token> INTLIT
%token <token> REALLIT
%token <token> BOOLLIT
%token <token> STRLIT
%token <token>  AND ASSIGN STAR DIV EQ GE GT LE LT MINUS MOD NE NOT OR PLUS
%token <token> LSHIFT RSHIFT DOTLENGTH PRINT PARSEINT RETURN  XOR
%token COMMA PUBLIC BOOL RESERVED INT DOUBLE  STATIC STRING VOID WHILE LBRACE LPAR LSQ RBRACE RPAR RSQ SEMICOLON ARROW CLASS ELSE IF
//testar com tudo a token


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


%union{
    struct token *token;
    struct node* node;
}

%%

Program:    CLASS ID LBRACE Program1 RBRACE         { $$=root= create_node("Program",gen_token("",num_line,num_column));
                                                        temp =create_node("Id",$2);
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
MethodDecl:  PUBLIC STATIC MethodHeader MethodBody  {$$ = create_node("MethodDecl",gen_token("",num_line,num_column));
                                                     adicionar_filho($$,$3);
                                                        adicionar_filho($$,$4);
                                                        
                                                       }
;

FieldDecl:   PUBLIC STATIC Type ID FieldDeclRep SEMICOLON {$$ = create_node("FieldDecl",gen_token("",num_line,num_column));
                                                                adicionar_filho($$,$3);
                                                                adicionar_filho($$,create_node("Id",$4));
                                                                if($5 != NULL){
                                                                    temp = $5;   
                                                                        while(temp!=NULL){
                                                                            
                                                                            temp2= create_node("FieldDecl",gen_token("",num_line,num_column));
                                                                             temp3=create_node($3->type,$3->token);
                                                                              adicionar_filho(temp2,temp3);
                                                                              adicionar_filho(temp2,create_node("Id",temp->token));
                                                                              adicionar_irmao($$,temp2);

                                                                             temp=temp->irmao;
                                                                       }
                                                                }
                                                           
                                                            }
   | error SEMICOLON                                    {$$ = NULL; }
   ;

FieldDeclRep: COMMA ID FieldDeclRep                         {$$ =temp=create_node("Id",$2);
                                                    adicionar_irmao($$,$3);
                                                   }  
|                                                       {$$= NULL;}
;

Type:       BOOL                                        {$$ = create_node("Bool",gen_token("",num_line,num_column));}
| INT                                                    {$$ =create_node("Int",gen_token("",num_line,num_column));}
| DOUBLE                                                {$$ =create_node("Double",gen_token("",num_line,num_column));}
;

MethodHeader:    Type  ID LPAR FormalParams  RPAR       {$$ = create_node("MethodHeader",gen_token("",num_line,num_column));
                                                          adicionar_filho($$,$1);
                                                          temp =create_node("Id",$2);
                                                          adicionar_filho($$,temp);
                                                            temp2= create_node("MethodParams",gen_token("",num_line,num_column));
                                                            adicionar_filho($$,temp2);
                                                             adicionar_filho(temp2,$4);
                                                           
                                                            }
| VOID ID LPAR FormalParams  RPAR                       {$$ = create_node("MethodHeader",gen_token("",num_line,num_column));
                                                        temp=create_node("Void",gen_token("",num_line,num_column));
                                                        adicionar_filho($$,temp);
                                                        adicionar_filho($$,create_node("Id",$2));
                                                        temp2 = create_node("MethodParams",gen_token("",num_line,num_column));
                                                        adicionar_filho($$,temp2);
                                                        adicionar_filho(temp2,$4);
                                                        
                                                        }
| Type  ID LPAR RPAR                                    {$$ = create_node("MethodHeader",gen_token("",num_line,num_column));
                                                         adicionar_filho($$,$1);
                                                         adicionar_filho($$,create_node("Id",$2));
                                                         temp2 = create_node("MethodParams",gen_token("",num_line,num_column));
                                                        adicionar_filho($$,temp2);
                                                         
                                                         }
| VOID ID LPAR RPAR                                     {$$ = create_node("MethodHeader",gen_token("",num_line,num_column));
                                                            temp=create_node("Void",gen_token("",num_line,num_column));
                                                            adicionar_filho($$,temp);
                                                            adicionar_filho($$,create_node("Id",$2));
                                                            temp2 = create_node("MethodParams",gen_token("",num_line,num_column));
                                                        adicionar_filho($$,temp2);
                                                            }
;

FormalParams:    Type ID FormalParams1                  {$$= create_node("ParamDecl",gen_token("",num_line,num_column));
                                                            adicionar_filho($$,$1);
                                                            adicionar_filho($$,create_node("Id",$2));
                                                            adicionar_irmao($$,$3);
                                                             } 
| STRING LSQ RSQ ID                                      {$$ = create_node("ParamDecl",gen_token("",num_line,num_column));
                                                            temp=create_node("StringArray",gen_token("",num_line,num_column));
                                                            adicionar_filho($$,temp);
                                                             adicionar_filho($$,create_node("Id",$4));
                                                             }
;

FormalParams1:  COMMA Type ID FormalParams1             {$$ = create_node("ParamDecl",gen_token("",num_line,num_column));
                                                            adicionar_filho($$,$2);
                                                            adicionar_filho($$,create_node("Id",$3));
                                                            adicionar_irmao($$,$4);
                                                           
                                                            }
|                                                       {$$= NULL;}
;

MethodBody: LBRACE MethodBody1 RBRACE               {$$ = create_node("MethodBody",gen_token("",num_line,num_column));
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

VarDecl: Type ID VarDeclRep SEMICOLON               {$$ = create_node("VarDecl",gen_token("",num_line,num_column));
                                                        adicionar_filho($$,$1);
                                                        adicionar_filho($$,create_node("Id",$2));
                                                       
                                                        if($3 != NULL){
                                                            temp=$3;
                                                            while(temp!=NULL){
                                                                temp2= create_node("VarDecl",gen_token("",num_line,num_column));
                                                                temp3=create_node($1->type,$1->token);
                                                                adicionar_filho(temp2,temp3);
                                                                adicionar_filho(temp2,create_node("Id",temp->token));
                                                                adicionar_irmao($$,temp2);
                                                                temp=temp->irmao;
                                                            }
                                                        }
                                                        }
;

VarDeclRep: COMMA ID VarDeclRep                         {$$ = temp = create_node("Id",$2);
                                                                adicionar_irmao($$,$3);
                                                              
                                                                }   
|                                                       {$$= NULL;}
;

Statement: LBRACE Statement1 RBRACE                {   
                                                        if ( block_count($2) > 1 ) {
														temp = create_node( "Block",gen_token("",num_line,num_column));
														$$ = temp;
														adicionar_filho(temp, $2);
														}
														else {
														$$ = $2;
															}
                                                           
                                                            }
| IF LPAR Expr RPAR Statement ELSE Statement {
                                                    $$ = create_node("If",gen_token("",num_line,num_column));
												adicionar_filho($$,$3);
												temp = create_node( "Block",gen_token("",num_line,num_column));
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
														    temp2 = create_node("Block",gen_token("",num_line,num_column));
															adicionar_filho($$, temp2);
															adicionar_filho(temp2, $7);
															}
													}
                                                  }
| IF LPAR Expr RPAR Statement                 { 
                                                $$=create_node("If",gen_token("",num_line,num_column));
                                                adicionar_filho($$,$3);
                                                temp = create_node("Block",gen_token("",num_line,num_column));
                                                if($5 != NULL && block_count($5) == 1 ){
                                                adicionar_filho($$,$5); 
                                                adicionar_filho($$, temp);
                                                }
                                                else{
                                                adicionar_filho($$,temp);
                                                adicionar_filho(temp,$5);
                                                adicionar_filho($$,create_node("Block",gen_token("",num_line,num_column)));
                                                }
                                              
                                              }
| WHILE LPAR Expr RPAR Statement             { 
                                                $$ = create_node( "While",gen_token("",num_line,num_column));
												adicionar_filho($$, $3);
												if (block_count($5) < 2 && $5 != NULL) {
													adicionar_filho($$, $5);
												}
												else {
													temp = create_node( "Block",gen_token("",num_line,num_column));
													adicionar_filho($$, temp);
													adicionar_filho(temp, $5);
												}
                                                
                                                }


| RETURN SEMICOLON      {$$= create_node("Return",$1);}
| RETURN Expr SEMICOLON      {$$= create_node("Return",$1);
                                adicionar_filho($$,$2);}
| MethodInvocation SEMICOLON     {$$=$1;}
| Assignment SEMICOLON   {$$=$1;}
| ParseArgs SEMICOLON   {$$=$1;}
| SEMICOLON {$$=NULL;}
| PRINT LPAR Expr RPAR SEMICOLON     {$$=create_node("Print",$1);
                                        adicionar_filho($$,$3);
                                          }
| PRINT LPAR STRLIT RPAR SEMICOLON  {$$ = create_node("Print",$1);
                                        temp = create_node("StrLit",$3);
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

    
MethodInvocation: ID LPAR RPAR                   {$$=create_node("Call",gen_token("",num_line,num_column));
                                                    temp=create_node("Id",$1);
                                                     adicionar_filho($$,temp); 
                                                     }

                | ID LPAR Expr MethodInvocation1 RPAR {$$=create_node("Call",gen_token("",num_line,num_column));
                                                    temp=create_node("Id",$1);
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


Assignment: ID ASSIGN Expr                                {$$ = create_node("Assign",$2);
                                                                temp=create_node("Id",$1);
                                                                adicionar_filho($$,temp);
                                                                adicionar_filho($$,$3);
                                                              }
;

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR               {$$ = create_node("ParseArgs",$1);
                                                                temp=create_node("Id",$3);
                                                                adicionar_filho($$,temp);
                                                                adicionar_filho($$,$5);
                                                                }
|   PARSEINT LPAR error RPAR                                {$$ = NULL;}
;

Expr: Assignment            {$$=$1;}
| Expr1                 {$$=$1;}
;

Expr1:     Expr1 PLUS Expr1            {$$ = create_node("Add",$2);
                                        adicionar_filho($$,$1);
                                        adicionar_filho($$,$3);
                                      }
| Expr1 MINUS Expr1                    {$$ = create_node("Sub",$2);
                                        adicionar_filho($$,$1);
                                        adicionar_filho($$,$3);
                                     }
| Expr1 STAR Expr1                      {$$ = create_node("Mul",$2);
                                            adicionar_filho($$,$1);
                                            adicionar_filho($$,$3);
                                        ;}
| Expr1 DIV Expr1                          {$$ = create_node("Div",$2);
                                                    adicionar_filho($$,$1);
                                                adicionar_filho($$,$3);
                                           }
| Expr1 MOD Expr1                              {$$ = create_node("Mod",$2);
                                                adicionar_filho($$,$1);
                                                adicionar_filho($$,$3);
                                            }
| Expr1 AND Expr1                                  {$$ = create_node("And",$2);
                                                    adicionar_filho($$,$1);
                                                    adicionar_filho($$,$3);}
                                             
                                               
| Expr1 OR  Expr1                                      {$$ = create_node("Or",$2);
                                                        adicionar_filho($$,$1);
                                                        adicionar_filho($$,$3);
                                                  }
| Expr1 XOR Expr1                                       {$$ = create_node("Xor",$2);
                                                        adicionar_filho($$,$1);
                                                            adicionar_filho($$,$3);
                                                        }
| Expr1 LSHIFT Expr1                                       {$$ = create_node("Lshift",$2);
                                                            adicionar_filho($$,$1);
                                                                adicionar_filho($$,$3);
                                                            }
| Expr1 RSHIFT Expr1                                          {$$ = create_node("Rshift",$2);
                                                            adicionar_filho($$,$1);
                                                                adicionar_filho($$,$3);
                                                             }
| Expr1 EQ Expr1                                                {$$ = create_node("Eq",$2);
                                                        adicionar_filho($$,$1);
                                                    adicionar_filho($$,$3);
                                                  }
| Expr1 GE Expr1                                                  {$$ = create_node("Ge",$2);
                                                                adicionar_filho($$,$1);
                                                            adicionar_filho($$,$3);
                                                           }
| Expr1 GT Expr1                                              {$$ = create_node("Gt",$2);
                                                             adicionar_filho($$,$1);
                                                            adicionar_filho($$,$3);
                                                          }
| Expr1 LE Expr1                                              {$$ = create_node("Le",$2);
                                                                        adicionar_filho($$,$1);
                                                                        adicionar_filho($$,$3);
                                                                   }
| Expr1 LT Expr1                                                  {$$ = create_node("Lt",$2);
                                                                adicionar_filho($$,$1);
                                                                adicionar_filho($$,$3);}
| Expr1 NE Expr1                                                  {$$ = create_node("Ne",$2);
                                                            adicionar_filho($$,$1);
                                                                adicionar_filho($$,$3);
                                                                }
| MINUS Expr1   %prec NOT                                    {$$ = create_node("Minus",$1);
                                                                adicionar_filho($$,$2);
                                                               }
| NOT Expr1                                            {$$ = create_node("Not",$1);
                                                                    adicionar_filho($$,$2);
                                                                    }
| PLUS Expr1      %prec NOT                                         {$$ = create_node("Plus",$1);
                                                                            adicionar_filho($$,$2);
                                                                            }
| LPAR Expr RPAR                                                    {$$=$2;}
| MethodInvocation                                                  {$$=$1;}
| ParseArgs                                                            {$$=$1;}
| ID                                                                      {$$ = create_node("Id",$1);}
| ID DOTLENGTH                                                              {$$ = create_node("Length",$2);
                                                                                adicionar_filho($$,create_node("Id",$1));
                                                                                } 
| INTLIT                                                                   {$$ = create_node("DecLit",$1);}
| REALLIT                                                                   {$$ = create_node("RealLit",$1);}
| BOOLLIT                                                                      {$$ = create_node("BoolLit",$1);}
| LPAR error RPAR                       {$$ = NULL;}
;


%%