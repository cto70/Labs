//
// Created by yarov on 02.11.2021.
//

#include "func.h"

int foo(int a, int b) {
    if (a > b)
        return a - b;
    else
        return b - a;
}