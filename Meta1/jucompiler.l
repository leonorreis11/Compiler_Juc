%{
    /* Ricardo Santiago 2020219352
    	   Leonor Reis 2019210146
    	*/

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	int num_line = 1;
	int num_column = 1;
	int column_begin=1;
	int line_begin=1;
	int flag=1;
	int e1=0;
	char * strlit;
%}

%X STRLIT COMMENT	COMMENTLINE
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
{intlit}							{if(e1 == 1)printf("INTLIT(%s)\n",yytext);num_column+=yyleng;}
{reallit1}|{reallit2}|{reallit3}    {if(e1 == 1)printf("REALLIT(%s)\n",yytext);num_column+=yyleng;}


(true)|(false)	{if(e1 == 1)printf("BOOLLIT(%s)\n",yytext);num_column+=yyleng;}
"&&"	{if(e1 == 1)printf("AND\n");num_column+=yyleng;}
"="	{if(e1 == 1)printf("ASSIGN\n");num_column+=yyleng;}
"*"	{if(e1 == 1)printf("STAR\n");num_column+=yyleng;}
","	{if(e1 == 1)printf("COMMA\n");num_column+=yyleng;}
"/"	{if(e1 == 1)printf("DIV\n");num_column+=yyleng;}
"=="	{if(e1 == 1)printf("EQ\n");num_column+=yyleng;}			
">="	{if(e1 == 1)printf("GE\n");num_column+=yyleng;}
">"		{if(e1 == 1)printf("GT\n");num_column+=yyleng;}
"{"		{if(e1 == 1)printf("LBRACE\n");num_column+=yyleng;}
"<="	{if(e1 == 1)printf("LE\n");num_column+=yyleng;}
"("		{if(e1 == 1)printf("LPAR\n");num_column+=yyleng;}
"["		{if(e1 == 1)printf("LSQ\n");num_column+=yyleng;}
"<"		{if(e1 == 1)printf("LT\n");num_column+=yyleng;}
"-"		{if(e1 == 1)printf("MINUS\n");num_column+=yyleng;}
"%"		{if(e1 == 1)printf("MOD\n");num_column+=yyleng;}
"!="	{if(e1 == 1)printf("NE\n");num_column+=yyleng;}
"!"		{if(e1 == 1)printf("NOT\n");num_column+=yyleng;}
"||"	{if(e1 == 1)printf("OR\n");num_column+=yyleng;}
"+"		{if(e1 == 1)printf("PLUS\n");num_column+=yyleng;}
"}"		{if(e1 == 1)printf("RBRACE\n");num_column+=yyleng;}
")"		{if(e1 == 1)printf("RPAR\n");num_column+=yyleng;}
"]"		{if(e1 == 1)printf("RSQ\n");num_column+=yyleng;}
";"		{if(e1 == 1)printf("SEMICOLON\n");num_column+=yyleng;}
"->"	{if(e1 == 1)printf("ARROW\n");num_column+=yyleng;}
"<<"	{if(e1 == 1)printf("LSHIFT\n");num_column+=yyleng;}
">>"	{if(e1 == 1)printf("RSHIFT\n");num_column+=yyleng;}
"^"		{if(e1 == 1)printf("XOR\n");num_column+=yyleng;}
"boolean"	{if(e1 == 1)printf("BOOL\n");num_column+=yyleng;}
"class"		{if(e1 == 1)printf("CLASS\n");num_column+=yyleng;}
".length"	{if(e1 == 1)printf("DOTLENGTH\n");num_column+=yyleng;}
"double"	{if(e1 == 1)printf("DOUBLE\n");num_column+=yyleng;}
"else"		{if(e1 == 1)printf("ELSE\n");num_column+=yyleng;}
"if"		{if(e1 == 1)printf("IF\n");num_column+=yyleng;}
"int"		{if(e1 == 1)printf("INT\n");num_column+=yyleng;}
"System.out.print"	{if(e1 == 1)printf("PRINT\n");num_column+=yyleng;}
"Integer.parseInt"	{if(e1 == 1)printf("PARSEINT\n");num_column+=yyleng;;}
"public"		{if(e1 == 1)printf("PUBLIC\n");num_column+=yyleng;}
"return"	{if(e1 == 1)printf("RETURN\n");num_column+=yyleng;}
"static"	{if(e1 == 1)printf("STATIC\n");num_column+=yyleng;}
"String"	{if(e1 == 1)printf("STRING\n");num_column+=yyleng;}
"void"		{if(e1 == 1)printf("VOID\n");num_column+=yyleng;}
"while"		{if(e1 == 1)printf("WHILE\n");num_column+=yyleng;}

{reserved}	{if(e1 == 1)printf("RESERVED(%s)\n",yytext);num_column+=yyleng;}
{id} {if(e1 == 1)printf("ID(%s)\n",yytext);num_column+=yyleng;}



{newline}											{num_column=1;num_line++;}
{space}												{num_column+=yyleng;}



\"	                                    			{BEGIN STRLIT;flag=0;strlit = yytext;column_begin=num_column;line_begin=num_line;num_column+=yyleng;}
<STRLIT>{strlit}									{num_column+=yyleng;}
<STRLIT>"\\"[^"f""n""r""t""\\"\"\n\r]?				{printf("Line %d, col %d: invalid escape sequence (%s)\n",num_line,num_column,yytext); num_column+=yyleng;flag=1;}
<STRLIT>{newline}										{printf("Line %d, col %d: unterminated string literal\n",line_begin,column_begin);num_column=1;num_line++;BEGIN 0;}
<STRLIT>\"											{num_column+=yyleng;if(e1==1&&flag==0){printf("STRLIT(%s)\n",strlit);}BEGIN 0;}
<STRLIT><<EOF>>						    			{printf("Line %d, col %d: unterminated string literal\n",line_begin,column_begin);num_column+=yyleng;BEGIN 0;}

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
	if (argc > 1) {
		if (strcmp(argv[1],"-l") == 0) {
			e1 = 1;
		}
		else if(strcmp(argv[1],"-e1") == 0) {
			e1 = 0;
		}
	}
	else if (argc == 1){
		e1 = 0;
	}
	yylex();
	return 0;
}

int yywrap() {
	return 1;
}