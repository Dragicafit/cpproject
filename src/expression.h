#ifndef DEF_EXPRESSION
#define DEF_EXPRESSION

#include <stdint.h>

int32_t par(int32_t exp1, operator op, int32_t exp2);
int32_t peek(int32_t exp);
int32_t aleat(int32_t exp);
int32_t cardinal();
int32_t self();
int32_t speed();
int32_t state(int32_t exp);
int32_t gpsx(int32_t exp);
int32_t gpsy(int32_t exp);
int32_t angle(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
int32_t TargetX(int32_t x1, int32_t angle, int32_t length);
int32_t TargetY(int32_t y1, int32_t angle, int32_t length);
int32_t distance(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
char condition(int32_t exp1, comparison comp, int32_t exp2);
void poke(int32_t add, int32_t value);
void ifThen(char condition, uint32_t number);
void engine(uint32_t angle, uint32_t speed);
#endif