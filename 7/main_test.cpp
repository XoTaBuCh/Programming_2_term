/*Copyright 2021 XoT@B*/
#include "main.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h> 

void test_hostel() {
    process();
    const char* fname = "hotel.txt";
    assert(countStrings(fname) == 13);
}

#undef main
int main() {
    test_hostel();
    getchar();
    return 0;
}
    