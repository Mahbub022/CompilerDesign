/* C Declarations */

%{
	#include<stdio.h>
	#include <string.h>
    extern	int yyerror(char *s);
	extern int yylex();
	extern int yyparse();
	extern FILE *yyin;
	extern FILE *yyout;
	extern int yylineno;

typedef struct {
    char *name;
    char *type;
    int intValue;
    double doubleValue;
    char *strValue;
    char charValue;
} Symbols;

Symbols data[20];
int countVar = 0 , countType = 0 ;
int countS = 1;
char varType[4][10]={"integer","float","character","string"};


void addValue(char *n, int t, int i,double d, char c, char *s)
{
    data[countVar].name= strdup(n);
    data[countVar].type= strdup(varType[t]);
    data[countVar].intValue = i;
    data[countVar].doubleValue = d;
    data[countVar].charValue = c;
    data[countVar].strValue = strdup(s);
}

int findVar(char *varName)
{
    int i=0;
    for(i ;i<=countVar;i++)
    {
        if(data[i].name != NULL && strcmp(data[i].name, varName) == 0)
        {
            return i;
        }
    }
    return 100;
}


void showVariable()
{
    printf("Variable\tType\tValue\n");
    int i=0;
    for(; i<=countVar;i++)
    {
        printf("%s\t%s\t", data[i].name, data[i].type);
        if(!strcmp( data[i].type,"integer"))
        {
            printf("%d\n", data[i].intValue);
        }
        else if(!strcmp( data[i].type,"float"))
        {
            printf("%.2f\n", data[i].doubleValue);
        }
        if(!strcmp( data[i].type,"character"))
        {
            printf("%c\n", data[i].charValue);
        }
        if(!strcmp( data[i].type,"string"))
        {
            printf("%s\n", data[i].strValue);
        }
    }
}


%}

/* bison declarations */

%union
{
    int intValue;
    float floatValue;
    char charValue;
    char* stringValue;
    char* dataType;
}
%start program
%token <stringValue> INT FLOAT CHAR STRING VAR LET IF ELSE ELSIF SWITCH CASE DO FOR WHILE IN BREAK CONTINUE START FINISH
%token <stringValue> AND OR EQUAl NOTEQUAL PLUS MINUS MULTIPLY DIVISION MODULO LESS GREATER LEFT RIGHT INCREMENT DECREMENT
%token SPACE ANY
%token <stringValue> HEADER COMMENT LETTERS
%token <floatValue> REAl
%token <intValue> DIGITS
%type <intValue> exp

%right ASSIGN DECLARE
%right MULTI SINGLE

%nonassoc IF
%nonassoc IFS

%right '=' PLUS MINUS MULTIPLY DIVISION MODULO
%left AND OR
%left '|' '&'
%left EQUAl NOTEQUAL
%left '<' '>'
%left LESS GREATER
%left LEFT RIGHT
%left '+' '-'
%left '*' '/' '%'
%right '^'
%right '!'
%right INCREMENT DECREMENT




/* Grammar rules and actions follow */
%%
	program: /*NULL*/
        | program lines
        
    lines: statements {printf("%d statement completed\n",countS); ++countS;}
        |ANY

    statements: comments
		| header_statement
        | variable_statement 
        | assignValue_statement
        | conditional_statement
        | null_statement
        | loop_statement

null_statement : ';' {printf("NUll statement\n");}

comments: COMMENT {if(yylval.stringValue[0]=='/' && yylval.stringValue[1]=='/'){printf("Single line comment started using //\n");}
 						else {printf("Multiple lines comment started using <! and finished using !>\n");}}

header_statement: HEADER {printf("Included header file is : %s\n",yylval.stringValue);}

loop_statement: FOR SPACE '(' forBlock ')' SPACE '[' statements']' {printf("<--For loop finished\n");}

forBlock: variable_statement SPACE ';' SPACE exp SPACE ';' SPACE value {printf("For loop started -->\n");}
        | assignValue_statement SPACE ';' SPACE exp ';' SPACE value {printf("For loop started -->\n");}

value : INCREMENT LETTERS 
        | DECREMENT LETTERS
        | LETTERS INCREMENT
        | LETTERS DECREMENT

conditional_statement:  IF SPACE '(' exp ')' SPACE '[' statements ']' SPACE ELSE SPACE '[' statements ']' %prec IFS {
                                                                printf("IF ELSE block started --");
                                                                if($4 != 0)
                                                                {
                                                                    printf("IF block will be executed\n");
                                                                }
                                                                else
                                                                {
                                                                    printf("ELSE block will be executed\n");
                                                                }
                                                                    }
                        | IF SPACE '(' exp ')' SPACE '[' statements ']' %prec IF {
                                                                printf("IF block started --");
                                                                if($4 != 0)
                                                                {
                                                                    printf("IF block will be executed\n");
                                                                }
                                                                else
                                                                {
                                                                    printf("NO block will be executed\n");
                                                                }
                                                                    }



assignValue_statement: LETTERS '=' exp { int count = findVar($1);
                                        if(count == 100)
                                        {
                                            printf("%s variable has not been declared\n",$1);
                                        }
                                        else
                                        {
                                            data[count].intValue = $3;
                                            printf("%d has been assigned to %s variable\n",$3,$1);
                                        }
                                            }
                    | LETTERS PLUS exp { int count = findVar($1);
                                        if(count == 100)
                                        {
                                            printf("%s variable has not been declared\n",$1);
                                        }
                                        else
                                        {
                                            $3 += data[count].intValue;
                                            data[count].intValue = $3;
                                            printf("%d has been assigned to %s variable\n",$3,$1);
                                        }
                                            }
                    | LETTERS MINUS exp { int count = findVar($1);
                                        if(count == 100)
                                        {
                                            printf("%s variable has not been declared\n",$1);
                                        }
                                        else
                                        {
                                            $3 -= data[count].intValue;
                                            data[count].intValue = $3;
                                            printf("%d has been assigned to %s variable\n",$3,$1);
                                        }
                                            }
                    | LETTERS MULTIPLY exp { int count = findVar($1);
                                        if(count == 100)
                                        {
                                            printf("%s variable has not been declared\n",$1);
                                        }
                                        else
                                        {
                                            $3 *= data[count].intValue;
                                            data[count].intValue = $3;
                                            printf("%d has been assigned to %s variable\n",$3,$1);
                                        }
                                            }
                    | LETTERS DIVISION exp { int count = findVar($1);
                                        if(count == 100)
                                        {
                                            printf("%s variable has not been declared\n",$1);
                                        }
                                        else
                                        {
                                            $3 /= data[count].intValue;
                                            data[count].intValue = $3;
                                            printf("%d has been assigned to %s variable\n",$3,$1);
                                        }
                                            }
                    | LETTERS MODULO exp { int count = findVar($1);
                                        if(count == 100)
                                        {
                                            printf("%s variable has not been declared\n",$1);
                                        }
                                        else
                                        {
                                            $3 /= data[count].intValue;
                                            data[count].intValue = $3;
                                            printf("%d has been assigned to %s variable\n",$3,$1);
                                        }
                                            }

                exp:  exp '*' exp {$$ = $1 * $3;  }
                    | exp '/' exp {$$ = $1 / $3;  }
                    | exp '%' exp {$$ = $1 % $3;  } 
                    |exp '+' exp { $$ = $1 + $3;  }
                    | exp '-' exp {$$ = $1 - $3;  }
                    | exp '<' exp {$$ = $1 < $3;  }
                    | exp '>' exp {$$ = $1 > $3;  }
                    | exp '^' exp {$$ = $1 ^ $3;  }
                    | exp AND exp {$$ = $1 && $3;  }
                    | exp OR exp {$$ = $1 || $3;  }
                    | exp LESS exp {$$ = $1 <= $3;  }
                    | exp GREATER exp {$$ = $1 >= $3;  }
                    | exp EQUAl exp {$$ = $1 == $3;  }
                    | exp NOTEQUAL exp {$$ = $1 != $3;  }
                    | exp '|' exp {$$ = $1 | $3;  }
                    | exp '&' exp {$$ = $1 & $3;  }
                    | DIGITS {$$ = $1;  }

variable_statement: Type SPACE variable
variable : singleVar multiVar

multiVar : /*NULL*/
        |',' multiVar multiVar %prec MULTI
        | singleVar %prec SINGLE

singleVar : LETTERS %prec DECLARE {
                                    if(findVar($1) == 1)
                                    {
                                        printf("Variable %s has been declared before\n",$1);
                                    }
                                    else
                                    {
                                        printf("Variable is : %s\n",$1); 
                                        data[countVar].name = strdup($1);
                                        data[countVar].type = strdup(varType[countType]);
                                        data[countVar].intValue = 0;
                                        ++countVar;
                                    }
                                                }
        | LETTERS '=' exp %prec ASSIGN {
                                        if(findVar($1) == 1)
                                        {
                                            printf("Variable %s has been declared before\n",$1);
                                        }
                                        else
                                        {
                                            data[countVar].name = strdup($1); data[countVar].intValue = $3;
                                            data[countVar].type= strdup(varType[countType]);
                                            printf("Variable: %s \t Value: %d \t type :%s\n",data[countVar].name,data[countVar].intValue,data[countVar].type);
                                            ++countVar;
                                        }
        }


Type : INT {countType = 0;}
    | FLOAT {countType = 1;}
    | CHAR {countType = 2;}
    | STRING {countType = 3;}

%%

int yyerror(char *s) {
    printf("Error at line %d: => %s\n",yylineno,s);
    return 0;
}

int main(void) {
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    yyparse();
}


/*
                                        char *n, int t, int i,double d, char c, char *s
                                        if(countType == 1)
                                        {
                                            d = 0;
                                            c = '0';
                                            s = strdup("NULL");
                                        }
                                        else if(countType == 2)
                                        {
                                            i = 0;
                                            c = '0';
                                            s = strdup("NULL");
                                        }
                                        else if(countType == 3)
                                        {
                                            i = 0;
                                            d = 0;
                                            c = strdup();
                                            s = strdup("NULL");

                                        } 
                                        else
                                        {
                                            d = 0;
                                            c = '0';
                                            s = strdup("NULL");
                                        }

*/