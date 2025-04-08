#ifndef LOGIC_H
#define LOGIC_H

#include "appcontext.h"
#include <stdlib.h>
#include <string.h>

#include <ctype.h>
#include <stdint.h>
#include <stdint.h>

void numericalRepresentation(int *number, const char* str);

int isValidDigit(char c, int base); //Проверяет символ на принадлежность к системе счисления
int charToValue(char c); //Преобразует символ в число
int isValidNumberInBase(const char *num, int base); //Проверяет ВСЁ число целиком на принадлежность к системе счисления
int isNumberInRange(const char *num, int base); //Проверяет, входит ли число в диапазон
int checkNumber(const char *num, int base); //Проверяет корректность введенного числа

#endif // LOGIC_H
