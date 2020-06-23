%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
%}

%option yylineno
%option noyywrap

id [a-zA-Z_][a-zA-Z_0-9]*
esp [ \n\t\r]
cadena \"([a-zA-Z0-9]*)\"
caracter \'([\x20-\x21\x23-\xFE])?\'
digito [0-9]
exponent ([Ee][+-]?{digito}+)
sufijo [fFlL]
entero {digito}+
real {digito}*"."{digito}+
cteFloat {digito}*("."({digito}+{exponent}{sufijo}))?
num {entero}|{real}|{cteFloat}

%%
 // Fecha: 23/05/2020
 // Autor: VMCR
 // Descripción: Declaración de los terminales que contiene la gramática
 // Modificación: 24/05/20
 // Modificó: ULM, JRA, DAOA, VMCR
 // Modificación: 25/05/20
 // Modificó:DAOA
"estructura"    {return STRUCT;}
"inicio"        {return START;}
"fin"           {return END;}
"ent"           {return INT;}
"real"          {return FLOAT;}
"dreal"         {return DOUBLE;}
"car"           {return CHAR;}
"sin"           {return VOID;}
"def"           {return DEF;}
"["             {return LSQBRACK;}
"]"             {return RSQBRACK;}
"si"            {return IF;}
"entonces"      {return THEN;}
"sino"          {return ELSE;}
"mientras"      {return WHILE;}
"hacer"         {return DO;}
"segun"         {return SWITCH;}
"escribir"      {return PRINT;}
"leer"          {return SCAN;}
"devolver"      {return RETURN;}
"pred"          {return PRED;}
"terminar"      {return BREAK;}
"caso"          {return CASE;}
"o"             {return OR;}
"y"             {return AND;}
"no"            {return NOT;}
"("             {return LPAR;}
")"             {return RPAR;}
"verdadero"     {return TRUE;}
"falso"         {return FALSE;}
">"             {return GREATER;}
"<"             {return LESS;}
"<="            {return LT;}
">="            {return GT;}
"<>"            {return NOTEQUAL;}
"="             {return EQUAL;}
"%"             {return MOD;}
"+"             {return PLUS;}
"-"             {return MINUS;}
"*"             {return MUL;}
"/"             {return DIV;}
"."             {return POINT;}
":"             {return COLON;}
";"             {return SEMICOLON;}
","             {return COMMA;}
":="            {return ASSIGN;}
{id}            {
                    strcpy(yylval.id, yytext);
                    return ID;
                }
{num}           {
                    yylval.num = atoi(yytext);
                    return NUM;
                }
{cadena}        {
                    strcpy(yylval.cadena, yytext);
                    return STRING;
                }
{caracter}        {
                    strcpy(yylval.caracter, yytext);
                    return CHAR;
                }
{esp}+  {} /*Ignora los espacios en blanco*/
.       {printf("Error léxico: %s en la línea %d\n", yytext,yylineno);}
%%