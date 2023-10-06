%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>

    typedef struct
    {
        char name[20];
        char type[20];
        char value[20];
    } variableInformation;

    variableInformation variable[20];
    char text[1000];
    int line=0,error=0,statement=0,variableCount=0;
    
    int isVariable(char s)
    {
        if(s>='a' && s<= 'z' || s>='A' && s<='Z' || s>='0' && s<='9')
        return 1;
    }

    int isOperator(char s)
    {
        if(s=='=')
        return 1;
    }

    void variableType(char *strText , int i, char *data , int length )
    {
        for(;i<length;i++)
        {
            int j=0;
            while(i<length && strText[i] == ' ')
            {
                ++i;
            }
            while(i<length && isVariable(strText[i]))
            {
                variable[variableCount].name[j++]=strText[i++];
                if(strText[i]==' ' | strText[i]==',' | strText[i]== '=' | strText[i]== 10 | i == length)
                {
                    strcpy(variable[variableCount++].type,data);
                    break;
                }
            }
            while(i<length && strText[i]!=',')
            {
                ++i;
            }
        }
    }

%}

Keyword (for|if|else|elsif|switch|catch|while|{Type})

SingleComment #[^#\n]+[\n]?
MultipleComment [/][/]([^/]*|[\n]*)+[/][/][\n]?
Comment {SingleComment}|{MultipleComment}

NewLine [\n]
Error .*

Digits [0-9]+ 
Number -?{Digits}
Float {Number}[.]{Digits}
String ["].*["]
Character ['].[']
Id [a-zA-Z_][a-zA-Z0-9_]*
Type (int|float|char|string)
VariableDeclare ([ ]*[=][ ]*({Number}|{Float}|{Character}|{String}))?([ ]*[,][ ]*{Id}([ ]*[=][ ]*({Number}|{Float}|{Character}|{String}))?)*[ ]*[\n]?
Variables {Type}[ ]*{Id}{VariableDeclare}

Relational ([<]|[>]|[<][=]|[>][=]|[<][>]|[=][=])
Arithmetic [-+*/%]
Assignment ([=]|[+][=]|[-][=]|[*][=]|[/][=]|[%][=])
Logical ([&][&]|[|][|]|[!])
Bitwise [~^|&]
Unary ([+][+]|[-][-])
Operator ({Arithmetic}|{Relational}|{Logical}|{Unary}|{Bitwise})
Prefix {Unary}{Id}
Postfix {Id}{Unary}
Expression (({Id}[ ]*{Assignment}[ ]*({Digits}|{Id})(([ ]*{Operator}[ ]*({Digits}|{Id}))?)*)|{Prefix}|{Postfix})[ ]*[\n]?

Input read[(]{Id}((,{Id})?)*[)][\n]?
Output write[(]{Id}((,{Id})?)*[)][\n]?
Statement {Variables}|{Expression}|{Input}|{Output}

Operation (({Id}[ ]*{Operator}[ ]*({Digits}|{Id})(([ ]*{Operator}[ ]*({Digits}|{Id}))?)*)|{Prefix}|{Postfix})
OperationIf (({Bitwise}|[!])[ ]*(({Id}|{Digits})|[(][ ]*{Operation}[ ]*[)]))|{Operation}
ExpressionIf {OperationIf}|[(][ ]*{OperationIf}[ ]*[)]
ConditionIf if[ ]*{ExpressionIf}[ ]*
StatementIf [ ]*{ConditionIf}[\n]?[ ]*[[][ ]*([\n]*[ ]*{Statement}[ ]*[\n]*)*[ ]*[]][ ]*[\n]?
IfElse {StatementIf}[ ]*else[ ]*[\n]?[ ]*[[][ ]*([\n]*[ ]*{Statement}[ ]*[\n]*)*[ ]*[]][\n]?

Seperator ";"
Initial {Variables}|({Id}{VariableDeclare}(([ ]*[,][ ]*{Id}{VariableDeclare})?)*)
Condition {Id}[ ]*({Relational}|{Logical})[ ]*{Id}(([ ]*({Relational}|{Logical})[ ]*{Id})?)*
Iteration {Prefix}|{Postfix}
Block [[][ ]*([\n]*[ ]*{Statement}[ ]*[\n]*)*[ ]*[]]
LoopFor "for"[ ]*[(][ ]*{Initial}?[ ]*{Seperator}[ ]*{Condition}?[ ]*{Seperator}[ ]*{Iteration}?[ ]*[)][ ]*[\n]*{Block}[\n]?

%%


{Input} {++line;++statement;printf("Input\n");printf("Line number : %d\n",line);}
{Output} {++line;++statement;printf("Output\n");printf("Line number : %d\n",line);}

{LoopFor} {++line;++statement;printf("For Loop\n");printf("Line number : %d\n",line);}

{StatementIf} {++line;++statement;printf("If condition\n");printf("Line number : %d\n",line);}
{IfElse} {++line;++statement;printf("If Else condition\n");printf("Line number : %d\n",line);}
{Expression} {++line;++statement;printf("Expression\n");printf("Line number : %d\n",line);}
{Variables} {++statement;printf("variable declared\n");++line;printf("Line number : %d\n",line);
            strcpy(text,yytext);
            int length=strlen(text); printf("%s\n",text); int i=0;
            for(;i<length;i++)
            {
                if(text[i]=='i' && text[i+1]=='n' && text[i+2]=='t')
                {                   
                    variableType(text,i+3,"Integer",length);
                    break;
                }
                else if(text[i]=='f' && text[i+1]=='l' && text[i+2]=='o' && text[i+3]=='a' && text[i+4]=='t')
                {
                    variableType(text,i+5,"Float",length);
                    break;
                }
                else if(text[i]=='c' && text[i+1]=='h' && text[i+2]=='a' && text[i+3]=='r')
                {
                    variableType(text,i+4,"Character",length);
                    break;
                }
                if(text[i]=='s' && text[i+1]=='t' && text[i+2]=='r' && text[i+3]=='i' && text[i+4]=='n' && text[i+5]=='g' )
                {
                    variableType(text,i+6,"String",length);
                    break;
                }
                else
                {
                    continue;
                }
            }
            }

{MultipleComment} {++line;printf("Multiple line Comment\n");printf("Line number : %d\n",line);}
{SingleComment} {++line;printf("Single line Comment\n");printf("Line number : %d\n",line);}

{Error} {++error;++line;printf("Error at line %d\n",line);}
{NewLine} {++line;printf("New Line %d\n",line);}
%%

int yywrap(){}

int main()
{
    printf("-----Language create-----\n");
    yyin=fopen("test.rm","r");
//    yyout=fopen("result.txt","a");
    yylex();
    int i=0;
    for(;i<variableCount;i++)
    {
        printf("Variable Type : %s\t name : %s\n",variable[i].type,variable[i].name);
    }
    return 0;
}