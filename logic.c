#include "logic.h"

void numericalRepresentation(int *number, const char* str){
    if (!strcmp(str, "Binary"))
      *number = bin;

    else if (!strcmp(str, "Octal"))
      *number = oct;

    else if (!strcmp(str, "Decimal"))
      *number = dec;

    else if (!strcmp(str, "Hexadecimal"))
      *number = hex;
}

int isValidDigit(char c, int base) {
    int flag = 0;

    if (isdigit(c))
      flag = (c - '0') < base;

    else if (isalpha(c))
      flag = (toupper(c) - 'A' + 10) < base;

    return flag;
}

int charToValue(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else if (isalpha(c)) {
        return toupper(c) - 'A' + 10;
    }
    return -1; // Недопустимый символ
}

int isValidNumberInBase(const char *num, int base) {
    int len = strlen(num), flag = 1;

    if (len == 0) {
        flag = 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isValidDigit(num[i], base)) {
            flag = 0;
        }
    }

    return flag;
}

int isNumberInRange(const char *num, int base) {
    //int64_t value = 0; //value заменить на context.answer
    int isNegative = 0;

    size_t len = strlen(num);

    // Преобразуем строку в число
    for (size_t i = 0; i < len; i++) {
        int digitValue = charToValue(num[i]);
        if (digitValue == -1 || digitValue >= base) {
            return 0;
        }
        context.answer = context.answer * base + digitValue;
    }

    if (isNegative) {
        context.answer -= (1LL << (len * ((base == 16) ? 4 : (base == 8 ? 3 : 1))));
        context.answer = -((int32_t)context.answer);
    }

    return context.answer >= INT32_MIN && context.answer <= INT32_MAX;
}

// Основная функция проверки строки
int checkNumber(const char *num, int base) {
    int flag = 1;
    if (!isValidNumberInBase(num, base)) {
        flag = 0; // Строка не является числом в указанной системе счисления
    }

    if (!isNumberInRange(num, base)) {
        flag = 0; // Число выходит за пределы диапазона 4 байт
    }

    return 1;
}
