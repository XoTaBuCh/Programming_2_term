/*Copyright 2021 XoT@B*/
#include "main.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int test_palindrome() {
	char *str = (char *)malloc(6 * sizeof(char));
	checkPtr(str);
	str = "abccba\0";
	assert(palindrome(&str, 6) == 1);
	str = "abcabc\0";
	assert(palindrome(&str, 6) == 0);
	str = "hfddfh\0";
	assert(palindrome(&str, 6) == 1);
}
#undef main
int main() {
    test_palindrome();
    return 0;
}