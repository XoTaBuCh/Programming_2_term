/*Copyright 2021 XoT@B*/
#include "main.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int test_tree() {
	FILE* fp = fopen("test1.txt", "r");
	checkPtr(fp);
    assert(filesize(fp) == 49);
	fclose(fp);
    fp = fopen("test2.txt", "r");
    assert(filesize(fp) == 35);
	fclose(fp);
}
#undef main
int main() {
    test_tree();
    return 0;
}