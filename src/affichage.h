#ifndef DEF_AFFICHAGE
#define DEF_AFFICHAGE

#include "parser.h"

const char* commandToString[] = {"WAIT", "POKE",   "GOTO",
                                 "IF",   "ENGINE", "SHOOT"};

const char* expressionToString[] = {
    "INT",   "PAR",  "PEEK", "RAND",  "CARDINAL", "SELF",    "SPEED",
    "STATE", "GPSX", "GPSY", "ANGLE", "TARGETX",  "TARGETY", "DISTANCE"};

const char* operatorToString[] = {"+", "-", "*", "/", "%"};

const char* comparisonToString[] = {"<", "<=", "=", "<>", ">=", ">"};

void printProgram(program* prog);
void printCommand(command* com);
void printExpression(expression* exp);
void printNumber(uint32_t number);
void printInteger(int32_t integer);
void printCondition(condition* cond);
void printOperator(operator op);
void printComparison(comparison comp);
void printLine(line* l);

#endif