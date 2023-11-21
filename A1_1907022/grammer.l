/* C Declarations */

%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include<math.h>
    #include "grammer.tab.h"
	
%}

/* RD and Actions */
%option yylineno

Digits [0-9]+
Float {Digits}[.]{Digits}
Letters [a-zA-Z_][a-zA-Z0-9_]*

Header (<{Letters}[.]h>)|([\"]{Letters}[.]h[\"])

SingleLine ([\/][\/][ ]*[^\/\n]+[\n])
MultiLine (<!([ ]|[\t]|[\n]|[^!<>])*!>)
Comments {SingleLine}|{MultiLine}

Type (int|float|char|string)

If "if"
Else "else"
Elsif "elsif"

Switch "switch"
Case "case"

For "for"
While "while"
Do "do"

Function "func"
Return "return"

Begin "Begin"
End "End"

Keyword {Type}|{If}|{Else}|{Elsif}|{Switch}|{Case}|{For}|{While}|{Do}|{Function}|{Return}|{Begin}|{End}

PostfixOP [+][+]|[-][-]
UnaryOp [!]
BasicOp [-+%\/*=><]
ShiftOp (<<|>>)
RelationalOp (<=|>=|==|!=|<|>|=)
BitwiseOp [|]|[&]|[\^]
LogicalOp ([|][|])|([&][&])
ConditionalOp [?:]
AssignmentOp ([+]=|-=|[*]=|[\/]=|%=)
Comma [,;]
Additional [#~@]
Braces [()\[\]{}\"\']

Operators {AssignmentOp}|{ShiftOp}|{RelationalOp}|{LogicalOp}|{BitwiseOp}|{UnaryOp}|{PostfixOP}|{BasicOp}|{ConditionalOp}|{Comma}|{Additional}|{Braces}

Newline [\n]+
Tab [\t]+
Space [ ]+
Unknown .

Any ([ ]|[\t]|[\n])*
Special {Newline}|{Tab}|{Space}

/* RE and Actions */


%%
{Comments} {yylval.stringValue = strdup(yytext); return COMMENT;}
{Header} {yylval.stringValue = strdup(yytext); return HEADER;}

"int" {yylval.stringValue = strdup(yytext); return INT;}
"float" {yylval.stringValue = strdup(yytext); return FLOAT;}
"char" {yylval.stringValue = strdup(yytext); return CHAR;}
"string" {yylval.stringValue = strdup(yytext); return STRING;}
"var" {yylval.stringValue = strdup(yytext); return VAR;}
"let" {yylval.stringValue = strdup(yytext); return LET;}
"if" {yylval.stringValue = strdup(yytext); return IF;}
"else" {yylval.stringValue = strdup(yytext); return ELSE;}
"elsif" {yylval.stringValue = strdup(yytext); return ELSIF;}
"switch" {yylval.stringValue = strdup(yytext); return SWITCH;}
"case" {yylval.stringValue = strdup(yytext); return CASE;}
"do" {yylval.stringValue = strdup(yytext); return DO;}
"for" {yylval.stringValue = strdup(yytext); return FOR;}
"while" {yylval.stringValue = strdup(yytext); return WHILE;}
"in" {yylval.stringValue = strdup(yytext); return IN;}
"break" {yylval.stringValue = strdup(yytext); return BREAK;}
"continue" {yylval.stringValue = strdup(yytext); return CONTINUE;}
"Begin" {yylval.stringValue = strdup(yytext); return START;}
"End" {yylval.stringValue = strdup(yytext); return FINISH;}

"&&" {yylval.stringValue = strdup(yytext); return AND;}
"||" {yylval.stringValue = strdup(yytext); return OR;}
"==" {yylval.stringValue = strdup(yytext); return EQUAl;}
"!=" {yylval.stringValue = strdup(yytext); return NOTEQUAL;}
"+=" {yylval.stringValue = strdup(yytext); return PLUS;}
"-=" {yylval.stringValue = strdup(yytext); return MINUS;}
"*=" {yylval.stringValue = strdup(yytext); return MULTIPLY;}
"/=" {yylval.stringValue = strdup(yytext); return DIVISION;}
"%=" {yylval.stringValue = strdup(yytext); return MODULO;}
"<=" {yylval.stringValue = strdup(yytext); return LESS;}
">=" {yylval.stringValue = strdup(yytext); return GREATER;}
"<<" {yylval.stringValue = strdup(yytext); return LEFT;}
">>" {yylval.stringValue = strdup(yytext); return RIGHT;}
"++" {yylval.stringValue = strdup(yytext); return INCREMENT;}
"--" {yylval.stringValue = strdup(yytext); return DECREMENT;}
{UnaryOp} {yylval.stringValue = strdup(yytext); return *yytext;}
{BasicOp} {yylval.stringValue = strdup(yytext); return *yytext;}
{BitwiseOp} {yylval.stringValue = strdup(yytext); return *yytext;}
{ConditionalOp} {yylval.stringValue = strdup(yytext); return *yytext;}
{Braces} {yylval.stringValue = strdup(yytext); return *yytext;}
{Comma} {return *yytext;}


{Letters} {yylval.stringValue = strdup(yytext); return LETTERS;}
{Float} {yylval.floatValue = atof(yytext); return REAl;}
{Digits} {yylval.intValue = atoi(yytext); return DIGITS;}

{Space} {return SPACE;}
{Any} {return ANY;}
[\n] {}
[\t] {}
[ ] {}
{Unknown} {}
%%

/* Extra Rules
{Special} {}
{Operators} {yylval.stringValue=strdup(yytext); return *yytext;}
{Keyword} {printf("Keyword : %s\n",yytext); return *yytext;}
*/

/* Additional part here */

int yywrap(){
return 1;
}