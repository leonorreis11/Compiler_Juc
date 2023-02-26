%{
	/* Ricardo Santiago 2020219352
	   Leonor Reis 2019210146
	*/

	#include "y.tab.h"
	#include "syntax_tree.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdarg.h>

	extern ast_tree *root;
	int num_line = 1;
	int num_column = 1;
	int column_begin=1;
	int line_begin=1;
	
	int flag=0;
	int tag=0;
	int tree_tag=0;
	int erros = 0;
	
	char strlit_char[256];
%}

%X STRLIT_Y COMMENT	COMMENTLINE
strlit	          ([^\n\r\\"]|\\n|\\f|\\r|\\\\|\\\"|\\t)*
newline			  \n|\r|(\r\n)
space	           " "|"\f"|"\t"

id	([A-Z]|[a-z]|"_"|"$")([A-Z]|[a-z]|"_"|"$"|[0-9])* 
intlit 0|[1-9]([0-9]+|"_"*[0-9]+)*
reallit1 [0-9]+("_"*[0-9]|[0-9])*"."(([eE][+-]?[0-9]+("_"*[0-9]|[0-9])*)|([0-9]+("_"*[0-9]|[0-9])*([eE][+-]?[0-9]+("_"*[0-9]|[0-9])*)?))
reallit2 "."[0-9]+("_"*[0-9]|[0-9])*([eE][+-]?[0-9]+("_"*[0-9]|[0-9])*)?|[0-9]+("_"*[0-9]|[0-9])*([eE][+-]?[0-9]+("_"*[0-9]|[0-9])*)
reallit3 [0-9]+("_"*[0-9]|[0-9])*"."

reserved "++"|"--"|"null"|"Integer"|"System"|"abstract"|"continue"|"for"|"new"|"switch"|"assert"|"default"|"package"|"synchronized"|"do"|"goto"|"private"|"this"|"break"|"implements"|"protected"|"throw"|"byte"|"import"|"throws"|"byte"|"import"|"throw"|"case"|"enum"|"instanceof"|"transient"|"catch"|"extends"|"short"|"try"|"char"|"final"|"interface"|"finally"|"long"|"strictfp"|"volatile"|"const"|"float"|"native"|"super"


%%
{intlit}							{if(tag)printf("INTLIT(%s)\n",yytext);num_column+=yyleng;
													yylval.id=(char *)strdup(yytext);
													if(tree_tag)return INTLIT;
													}

{reallit1}|{reallit2}|{reallit3}    {if(tag)printf("REALLIT(%s)\n",yytext);num_column+=yyleng;		
													yylval.id=(char *)strdup(yytext);
													if(tree_tag)return REALLIT;
													}


(true)|(false)	{if(tag)printf("BOOLLIT(%s)\n",yytext);num_column+=yyleng;
													yylval.id=(char *)strdup(yytext);
													if(tree_tag)return BOOLLIT;
													}
"&&"	{if(tag)printf("AND\n");num_column+=yyleng;if(tree_tag)return AND;}
"="	{if(tag)printf("ASSIGN\n");num_column+=yyleng;if(tree_tag)return ASSIGN;}
"*"	{if(tag)printf("STAR\n");num_column+=yyleng;if(tree_tag)return STAR;}
","	{if(tag)printf("COMMA\n");num_column+=yyleng;if(tree_tag)return COMMA;}
"/"	{if(tag)printf("DIV\n");num_column+=yyleng;if(tree_tag)return DIV;}
"=="	{if(tag)printf("EQ\n");num_column+=yyleng;if(tree_tag)return EQ;}			
">="	{if(tag)printf("GE\n");num_column+=yyleng;if(tree_tag)return GE;}
">"		{if(tag)printf("GT\n");num_column+=yyleng;if(tree_tag)return GT;}
"{"		{if(tag)printf("LBRACE\n");num_column+=yyleng;if(tree_tag)return LBRACE;}
"<="	{if(tag)printf("LE\n");num_column+=yyleng;if(tree_tag)return LE;}
"("		{if(tag)printf("LPAR\n");num_column+=yyleng;if(tree_tag)return LPAR;}
"["		{if(tag)printf("LSQ\n");num_column+=yyleng;if(tree_tag)return LSQ;}
"<"		{if(tag)printf("LT\n");num_column+=yyleng;if(tree_tag)return LT;}
"-"		{if(tag)printf("MINUS\n");num_column+=yyleng;if(tree_tag)return MINUS;}
"%"		{if(tag)printf("MOD\n");num_column+=yyleng;if(tree_tag)return MOD;}
"!="	{if(tag)printf("NE\n");num_column+=yyleng;if(tree_tag)return NE;}
"!"		{if(tag)printf("NOT\n");num_column+=yyleng;if(tree_tag)return NOT;}
"||"	{if(tag)printf("OR\n");num_column+=yyleng;if(tree_tag)return OR;}
"+"		{if(tag)printf("PLUS\n");num_column+=yyleng;if(tree_tag)return PLUS;}
"}"		{if(tag)printf("RBRACE\n");num_column+=yyleng;if(tree_tag)return RBRACE;}
")"		{if(tag)printf("RPAR\n");num_column+=yyleng;if(tree_tag)return RPAR;}
"]"		{if(tag)printf("RSQ\n");num_column+=yyleng;if(tree_tag)return RSQ;}
";"		{if(tag)printf("SEMICOLON\n");num_column+=yyleng;if(tree_tag) return SEMICOLON;}
"->"	{if(tag)printf("ARROW\n");num_column+=yyleng;if(tree_tag) return ARROW;}
"<<"	{if(tag)printf("LSHIFT\n");num_column+=yyleng;if(tree_tag)return LSHIFT;}
">>"	{if(tag)printf("RSHIFT\n");num_column+=yyleng;if(tree_tag)return RSHIFT;}
"^"		{if(tag)printf("XOR\n");num_column+=yyleng;if(tree_tag)return XOR;}
"boolean"	{if(tag)printf("BOOL\n");num_column+=yyleng;if(tree_tag)return BOOL;}
"class"		{if(tag)printf("CLASS\n");num_column+=yyleng;if(tree_tag)return CLASS;}
".length"	{if(tag)printf("DOTLENGTH\n");num_column+=yyleng;if(tree_tag)return DOTLENGTH;}
"double"	{if(tag)printf("DOUBLE\n");num_column+=yyleng;if(tree_tag)return DOUBLE;}
"else"		{if(tag)printf("ELSE\n");num_column+=yyleng;if(tree_tag)return ELSE;}
"if"		{if(tag)printf("IF\n");num_column+=yyleng;if(tree_tag)return IF;}
"int"		{if(tag)printf("INT\n");num_column+=yyleng;if(tree_tag)return INT;}
"System.out.print"	{if(tag)printf("PRINT\n");num_column+=yyleng;if(tree_tag)return PRINT;}
"Integer.parseInt"	{if(tag)printf("PARSEINT\n");num_column+=yyleng;;if(tree_tag)return PARSEINT;}
"public"		{if(tag)printf("PUBLIC\n");num_column+=yyleng;if(tree_tag)return PUBLIC;}
"return"	{if(tag)printf("RETURN\n");num_column+=yyleng;if(tree_tag)return RETURN;}
"static"	{if(tag)printf("STATIC\n");num_column+=yyleng;if(tree_tag)return STATIC;}
"String"	{if(tag)printf("STRING\n");num_column+=yyleng;if(tree_tag)return STRING;}
"void"		{if(tag)printf("VOID\n");num_column+=yyleng;if(tree_tag)return VOID;}
"while"		{if(tag)printf("WHILE\n");num_column+=yyleng;if(tree_tag)return WHILE;}

{reserved}	{if(tag)printf("RESERVED(%s)\n",yytext);num_column+=yyleng;if(tree_tag)return RESERVED;}
{id} {if(tag)printf("ID(%s)\n",yytext);num_column+=yyleng;
													yylval.id=(char *)strdup(yytext);
													if(tree_tag)return ID;}



{newline}											{num_column=1;num_line++;}
{space}												{num_column+=yyleng;}



\"	                                    			{BEGIN STRLIT_Y;flag=0;strlit_char[0] = 0;strcat(strlit_char,yytext);column_begin=num_column;line_begin=num_line;num_column+=yyleng;}
<STRLIT_Y>{strlit}									{num_column+=yyleng;strcat(strlit_char,yytext);}
<STRLIT_Y>"\\"[^"f""n""r""t""\\"\"\n\r]?				{strcat(strlit_char,yytext);printf("Line %d, col %d: invalid escape sequence (%s)\n",num_line,num_column,yytext); num_column+=yyleng;flag=1;}
<STRLIT_Y>{newline}										{strlit_char[0] = 0;printf("Line %d, col %d: unterminated string literal\n",line_begin,column_begin);num_column=1;num_line++;BEGIN 0;}
<STRLIT_Y>\"											{strcat(strlit_char,yytext);num_column+=yyleng;if(tag&&flag==0){printf("STRLIT(%s)\n",strlit_char);}BEGIN 0;
													if(tree_tag && flag ==0){
													yylval.id=(char *)strdup(strlit_char);
													yytext=strlit_char;
													return STRLIT;}
													}
<STRLIT_Y><<EOF>>						    			{strlit_char[0] = 0;printf("Line %d, col %d: unterminated string literal\n",line_begin,column_begin);num_column+=yyleng;BEGIN 0;}

"/*"										{BEGIN COMMENT;column_begin=num_column;line_begin=num_line;num_column+=yyleng;}
<COMMENT>"*/"								{num_column+=yyleng;BEGIN 0;}
<COMMENT>{newline}							{num_column=1;num_line++;}
<COMMENT>.									{num_column+=yyleng;}
<COMMENT><<EOF>>							{printf("Line %d, col %d: unterminated comment\n",line_begin,column_begin);BEGIN 0;}

"//"										{BEGIN COMMENTLINE;num_column+=yyleng;}
<COMMENTLINE>{newline}							{BEGIN 0;num_line++;num_column=1;}
<COMMENTLINE>.								{num_column+=yyleng;}


	
.			{printf("Line %d, col %d: illegal character (%s)\n",num_line,num_column,yytext); num_column+=yyleng;}	


%%
int main(int argc, char *argv[])
{
	if(argc>1){
	 
	 
        if (strcmp(argv[1],"-l") == 0){
            tag = 1;
            yylex();
        }
        else if (strcmp(argv[1], "-e1") == 0){
            yylex();
        }
       else if (strcmp(argv[1],"-t") == 0){
            tree_tag = 1;
            yyparse();
            if(!erros) print_tree(root, 0);
        }
        else if (strcmp(argv[1], "-e2") == 0) {
            tree_tag = 1;
            yyparse();
        }	
    }

    else
        yyparse();
    
    if(root != NULL)
        free_tree(root);
    
    return 0;
}

int yywrap() {
	return 1;
}

void yyerror(const char *s) { 
	erros++;
   printf ("Line %d, col %d: %s: %s\n", num_line, (int)(num_column-strlen(yytext)), s, yytext);
}

