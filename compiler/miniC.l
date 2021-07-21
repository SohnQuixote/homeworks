%{
// lex source for MiniC
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ID_LENGTH 12
#define NO_OP 44
#include "minic.tab.h"
struct tokenType{
int number;
union{
char id[ID_LENGTH];
int num;
}value;
};
//extern char* yylval;
char* TokenToString(char *token);
struct tokenType token;
%}
%%
"const"	return(tconst);
"else"		return(telse);
"if"		return(tif);
"int"		return(tint);
"return"	return(treturn);
"void"		return(tvoid);
"while"	return(twhile);
"=="		return(tequal);
"!="		return(tnotequ);
"<="		return(tlesse);
">="		return(tgreate);
"&&"		return(tand);
"||"		return(tor);
"++"		return(tinc);
"--"		return(tdec);
"+="		return(taddAssign);
"-="		return(tsubAssign);
"*="		return(tmulAssign);
"/="		return(tdivAssign);
"%="		return(tmodAssign);
"/"		return (tdiv);
"!"		return (tnot);
"%"		return (tmod);
"*"		return (tmul);
"+"		return (tplus);
"-"		return (tminus);
"<"		return (tless);
">"		return (tgreat);
"="		return (tassign);
"("		return (tlparen);
")"		return (trparen);
","		return (tcomma);
";"		return (tsemicolon);
"["		return (tlbracket);
"]"		return (trbracket);
"{"		return (tlbrace);
"}"		return (trbrace);
[A-Za-z_][A-Za-z0-9_]*		{yylval.string = TokenToString(yytext);return(tident);}
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?	{yylval.string = TokenToString(yytext); return(tnumber);}
"/*"([^*]|\*+[^*])*\**"*/"	;
"//".*				;
[ \t\n]			;
.		return(yytext[0]);
%%
int yywrap()
{
//printf("End of MiniC\n");
return 1;
}


