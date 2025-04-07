#ifndef APPCONTEXT_H
#define APPCONTEXT_H

struct AppContext{
    char answer[64];
    const char* input;
    int fromBase;
    int toBase;
    int flag;
    int negative_flag;
};

#endif // APPCONTEXT_H
