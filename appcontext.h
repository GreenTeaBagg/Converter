#ifndef APPCONTEXT_H
#define APPCONTEXT_H

enum Notations {
    bin = 2,
    oct = 8,
    dec = 10,
    hex = 16
};

struct AppContext {
    int answer = 0;
    char answerStr[64];
    const char* input;
    int inputBase = dec;
    int outputBase = dec;
};

#endif // APPCONTEXT_H
