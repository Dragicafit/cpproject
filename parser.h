#ifndef DEF_PARSER
#define DEF_PARSER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char isInteger(char* name);
char isNumber(char* name);
char isOperator(char name);
char isComparaison(char* name);
char isExpression(FILE* f, char* name);
void parser(int argc, char* argv[]);

#endif