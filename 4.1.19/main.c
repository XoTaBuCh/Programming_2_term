/*Пусть слово – это последовательность от 1 до 8
символов, не включающая пробелов. Вводится n слов s1, ..., sn.
Можно ли их упорядочить так, чтобы получилась «цепочка»,
в которой первая буква каждого слова si совпадает с последней буквой
предыдущего слова, а последняя буква последнего слова совпадает с
первой буквой первого слова? В цепочку должны входить все n слов
без повторений. Если такое упорядочение возможно, то вывести
цепочку слов.*/

#include "stdio.h"
#include <stdlib.h>
#include <string.h>

int my_strlen(char c_str[]) {
	int count = 0;
	for (count; c_str[count] != '\0'; count++) {}
	return count;
}

int main() {
	int N;
	printf("Enter n:\n");
	while (scanf("%d", &N) != 1 || N < 2 || N > 255) {
		printf("ERROR! Enter integer > 1\n");
		while (getchar() != '\n') {}
	}
	char words[256][9];
	for (int i = 0; i < N; i++) {
		printf("Enter %d word: ", i + 1);
		rewind(stdin);
		for (int k = 0; k < 9; k++) {
			scanf("%c", &words[i][k]);
			if (words[i][k] == '\n') {
				words[i][k] = '\0';
				break;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int r = my_strlen(words[i]) - 1;
			if (words[j][0] == words[i][r]) {
				char temp[9];
				for (int k = 0; k < 9; k++) {
					temp[k] = words[i + 1][k];
				}
				for (int k = 0; k < 9; k++) {
					words[i + 1][k] = words[j][k];
				}
				for (int k = 0; k < 9; k++) {
					words[j][k] = temp[k];
				}
				break;
			} else if (words[j][0] != words[i][r] && i + 1 >= N) {
				printf("ERROR!\n");
				return 0;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int k = 0; words[i][k] != '\0'; k++) {
			printf("%c", words[i][k]);
		}
		printf(" ");
	}
	while (getchar() != '\n') {}
	return 0;
}
