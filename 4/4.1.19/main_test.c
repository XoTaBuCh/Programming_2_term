/*Copyright 2021 XoT@B*/
#include "main.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int test_str() {
    assert(my_strlen("elephant") == 8);
    assert(my_strlen("open") == 4);
    assert(my_strlen("kengoo") == 6);
}
#undef main
int main() {
    test_str();
    return 0;
}