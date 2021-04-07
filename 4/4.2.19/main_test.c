/*Copyright 2021 XoT@B*/
#include "main.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int test_file() {
    assert(my_strlen("elephant") == 8);
    assert(my_strlen("open") == 4);
    assert(my_strlen("kengoo") == 6);
    char * str1 = "asd", * str2 = "aasfadf", * str3 = "x";
    assert(lesser_length(str1, str2) == 3);
    assert(lesser_length(str1, str3) == 1);
}
#undef main
int main() {
    test_file();
    return 0;
}