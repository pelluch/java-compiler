%{
	#include "hashtable.h"
	#include "stringtable.h"
	#include "bison.h"
	int flag = 0;
	extern YYLTYPE yylloc;
	#define YY_USER_INIT yylloc.first_line=1;
%}

%option yylineno

char* numToString(int value);
StringChar	[\ a-zA-Z]|[\\n]
SingleQuote	[']
DoubleQuote	["]
Underscore	[_]
Letter	[a-zA-Z]
Digit 	[0-9]
Dot	[.]
Identifier ({Letter}|{Underscore})({Letter}|{Digit}|{Underscore})*
Integer	{Digit}+
StringLiteral	{DoubleQuote}{StringChar}*{DoubleQuote}
CharLiteral	{SingleQuote}{Letter}{SingleQuote}
FloatingPointLiteral	{Digit}+{Dot}{Digit}+|{Digit}+|{Dot}{Digit}+|{Digit}+[\.]
MultiCommentStart [\/][\*]
MultiCommentEnd [\*][\/]
%%
{MultiCommentStart}			{ 
								if(flag == 0)
								{	
									flag = 1;
								}
 							}
 							
{MultiCommentEnd}			{ 
								if(flag == 1)
								{
									flag = 0;
								}
							}
							
true|false				{ if(flag == 0) { yylval.str = strdup(yytext); return TrueOrFalse;  }}
boolean					{ if(flag == 0) { yylval.str = strdup(yytext);return Boolean; }}
float					{ if(flag == 0) { yylval.str = strdup(yytext);return Float; }}
int					{ if(flag == 0) { yylval.str = strdup(yytext);return Int; }}
char				{ if(flag == 0) { yylval.str = strdup(yytext); return Char; }}
[\^]					{ if(flag == 0) { yylval.str = strdup(yytext);return Tongo; }}
[\|][\|]			{ if(flag == 0) { yylval.str = strdup(yytext);return OrOr; }}
[\&][\&]			{ if(flag == 0) { yylval.str = strdup(yytext);return AndAnd; }}
[\|]					{ if(flag == 0) { yylval.str = strdup(yytext);return Or; }}
[\[]				{ if(flag == 0) { yylval.str = strdup(yytext);return OpenCorchete; }}
[\]]				{ if(flag == 0) { yylval.str = strdup(yytext);return CloseCorchete; }}
[.]					{ if(flag == 0) { yylval.str = strdup(yytext);return punto;}}
public|protected|private		{ if(flag == 0) { yylval.str = strdup(yytext);return modifier; }}
class					{ if(flag == 0) { yylval.str = strdup(yytext);return Class; }}
extends					{ if(flag == 0) { yylval.str = strdup(yytext);return Extends; }}
[{]						{ if(flag == 0) { yylval.str = strdup(yytext);return OpenLlave; }}
[}]						{ if(flag == 0) { yylval.str = strdup(yytext);return CloseLlave; }}
[,]					{ if(flag == 0) { yylval.str = strdup(yytext);return Coma; }}
[;]					{ if(flag == 0) { yylval.str = strdup(yytext);return PuntoComa; }}
[+]|[-]					{ if(flag == 0) { yylval.str = strdup(yytext);return AddOp; }}
[+][+]				{ if(flag == 0) { yylval.str = strdup(yytext);return PlusPlus; }}
[-][-]				{ if(flag == 0) { yylval.str = strdup(yytext);return MinusMinus; }}
[!]|[~]					{ if(flag == 0) { yylval.str = strdup(yytext);return Not; }}
[<]|[>]|[<][=]|[>][=]		{ if(flag == 0) { yylval.str = strdup(yytext);return Relacion; }}
[=][=]|[!][=]				{ if(flag == 0) { yylval.str = strdup(yytext);return Igualdad; }}
[\/]|[\*]|[\%]				{ if(flag == 0) { yylval.str = strdup(yytext);return MultOp; }}
[=] 						{ if(flag == 0) { yylval.str = strdup(yytext);return Equals; }}
[\*][=]|[\/][=]|[\%][=]|[+][=]|[-][=]|[\^][=]|[\|][=]|[&][=] { if(flag == 0) { yylval.str = strdup(yytext);return variableDeclarator; }}
[\&]					{ if(flag == 0) { yylval.str = strdup(yytext);return And; }}
void					{ if(flag == 0) { yylval.str = strdup(yytext);return Void; }}
[(]						{ if(flag == 0) { yylval.str = strdup(yytext);return OpenParentesis; }}
[)]						{ if(flag == 0) { yylval.str = strdup(yytext);return CloseParentesis; }}
this					{ if(flag == 0) { yylval.str = strdup(yytext);return This; }}
super					{ if(flag == 0) { yylval.str = strdup(yytext);return super; }}
if					{ if(flag == 0) { yylval.str = strdup(yytext);return If; }}
else					{ if(flag == 0) { yylval.str = strdup(yytext);return Else; }}
switch					{ if(flag == 0) { yylval.str = strdup(yytext);return Switch; }}
case					{ if(flag == 0) { yylval.str = strdup(yytext);return Case; }}
default					{ if(flag == 0) { yylval.str = strdup(yytext);return Default; }}
[:]					{ if(flag == 0) { yylval.str = strdup(yytext);return DosPtos; }}
while					{ if(flag == 0) { yylval.str = strdup(yytext);return While; }}
do					{ if(flag == 0) { yylval.str = strdup(yytext);return Do; }}
for					{ if(flag == 0) { yylval.str = strdup(yytext);return For; }}
break					{ if(flag == 0) { yylval.str = strdup(yytext);return Break; }}
continue				{ if(flag == 0) { yylval.str = strdup(yytext);return Continue; }}
return					{ if(flag == 0) { yylval.str = strdup(yytext);return Return; }}
new					{ if(flag == 0) { yylval.str = strdup(yytext);return New; }}
{Integer}				{ if(flag == 0) { yylval.str = strdup(yytext);return IntegerLiteral; }}
{FloatingPointLiteral}			{ if(flag == 0) { yylval.str = strdup(yytext);return FloatingPointLiteral;}}
{StringLiteral} 			{ if(flag == 0) { yylval.str = strdup(yytext);return StringLiteral; }}
{CharLiteral}				{ if(flag == 0) { yylval.str = strdup(yytext);return CharLiteral; }}
{DoubleQuote}				{ if(flag == 0) { yylval.str = strdup(yytext);return DoubleQuote;}}
{Identifier}				{ if(flag == 0) { yylval.str = strdup(yytext);return Identifier; }}
[\/][\/].*				;
[\n]					{ yylloc.first_line++; }
[ \t]+					;
.						{ if(flag == 0) return Error; }
%%
/*
char * numToString(int value)
{
	switch(value)
	{
		case Identifier: return (char *)"Identifier";
		case IntegerLiteral: return (char *)"Int";
		case SingleQuote: return (char *)"Single Quote";
		case DoubleQuote: return (char *)"Double Quote";
		case Letter: return (char *)"Letter";
		case StringLiteral: return (char *)"String literal";
		case CharLiteral: return (char *)"Char literal";
		case FloatingPointLiteral: return (char *)"Float literal";
		default: return (char *)"keyword";
	}
}

int main()
{
	int value = 0;
	int blah = 1;
	int i;
	int length;
	
	//Esto es 1 cuando encontramos un multicomment start
	int doubeQuoteFlag = 0; //0 = closed, 1 = open
	HashTableAlloc();
	StringTableAlloc();
	int numFound = 0;
	int val = yylex();
	char* toPrint;
	int sum = 0;

	while(val != 0)
	{	
		if(flag == 0)
		{
			
			if(val == Error)
			{
				printf("Encontrado error léxico en la línea %d: %s\n", yylineno, yytext);
			}
			else
			{
				toPrint = numToString(val);
				printf("Found %s: %s with enum code %3d on line number %3d.\n", toPrint, yytext, val, yylineno);
							
					if(val == Identifier)
					{
						struct Slot *id = buscaInserta(yytext);
						printf("Identificador tiene valor: %d\n", (int)id);
					}	
					else if(val == StringLiteral)
					{
						struct Slot *str = buscaInsertaString(yytext);
						printf("String literal tiene valor asociado: %d\n", (int)str);
					}
					/*else if(val == TrueOrFalse || val == CondicionalExpr || val == Corchete || val == modifier || val == Llave || val == AddOp || val == IncrementExpr || val == Not || val == variableDeclarator || val == Comparacion || val == MultOp || val == Parentesis)
					{
						sum = 0;
						length = strlen(yytext);
						for(i = 0; i < length; i++)
						{
							sum += yytext[i];
						}
						printf("Valor del token %s grupo %d: %d\n", yytext, val, sum);
					}
					
					
			}	
		
		}	
		val = yylex();	
	}
	if(flag == 1)
	{
		printf("Error! Comentario multilínea no ha sido cerrado.\n");
	}
	printf("\n****Printing the identifiers' table****\n");
	HashTablePrint();
	printf("\n****Printing the string table****\n");
	StringTablePrint();
	printf("\n");
}
*/
