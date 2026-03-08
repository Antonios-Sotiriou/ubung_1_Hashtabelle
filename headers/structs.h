#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>

typedef struct AktieData {
    std::string date;
    int volume;
    float close, open, high, low;
} AktieData;

#endif // !STRUCTS_H