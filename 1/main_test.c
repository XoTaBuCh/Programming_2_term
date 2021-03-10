/*Copyright 2021 XoT@B*/
#include "main.h"
#include <assert.h>

int test_double() {
assert(Double("123.456") == 15);
assert(Double("123.111") == 6);
assert(Double("0.0") == 0);
assert(Double("1") == 1);
assert(Double("457") == 16);
assert(Double("0.784") == 19);
assert(Double("99999999999.9999") == 99);
assert(Double("0") == 0);
assert(Double("11111.111111111111") == 12);
assert(Double("87451.74") == 25);
}
#undef main
int main() {
test_double();
}
