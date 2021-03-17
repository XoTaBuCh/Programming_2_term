/*Copyright 2021 XoT@B*/
#include "main.h"
#include <assert.h>

int test_taylor() {
    assert(FindN(1, 0.1) == 2);
    assert(FindN(1, 0.001) == 3);
    assert(FindN(1, 0.0001) == 4);
    assert(FindN(4, 0.01) == 7);
    assert(FindN(1.5, 0.0001) == 5);
    assert(FindN(0.2, 0.042) == 1);
    }
#undef main
int main() {
    test_taylor();
}
