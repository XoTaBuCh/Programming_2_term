/*Copyright 2021 XoT@B*/
#include "main.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int test_step() {
    int n = 6, m = 6;
    int** Array = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		Array[i] = (int*)malloc(m * sizeof(int));
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			Array[i][k] = 0;
		}
	}
	Array[n - 1][0] = 2;
    assert(Step(3, 3, Array) == 1);
    assert(Step(3, 3, Array) == 0);
    assert(Step(5, 0, Array) == 2);
    for (int i = 0; i < n; i++) {
	    free(Array[i]);
	}
	free(Array);
    return 0;
}
#undef main
int main() {
    test_step();
    return 0;
}