/*В файле задан произвольный текст. Напечатать в алфавитном
порядке все слова, которые входят в этот текст по одному разу.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int my_strlen(char c_str[]) {
	int count = 0;
	for (count; c_str[count] != '\0'; count++);
	return count;
}

int lesser_length(char* s1, char* s2)
{
	return ((my_strlen(s1) < my_strlen(s2)) ? my_strlen(s1) : my_strlen(s2));  
}

int main()
{
	char s[1025] = { 0 }, result[100][200];

	FILE* f = NULL;
	if (fopen_s(&f, "input.txt", "r"))
	{
		perror("Cannot open file.\n");
		exit(-3);
	}

	while (!feof(f))
	{
		fgets(s, 1024, f);
	}
	fclose(f);

	printf("String: %s \n", s);

	char word[100], * p, * start = s;
	int i = 0, j = 0, n = 0, k = 0, m = 0;
	while (s[i]) {
		if (s[i] != ',' && s[i] != '.' && s[i] != ' ') {
			word[j] = s[i];
			j++;
		}
		else {
			word[j] = '\0';
			j = 0;
			while (1) {
				p = strstr(start, word);
				if (p == NULL) break;
				n++;
				if (n > 1) { break; }
				start = p + my_strlen(word);
			}
			if (n <= 1 && p == NULL) {
				for (int f = 0; f < my_strlen(word); f++) {
					result[k][f] = word[f];
					result[k][my_strlen(word)] = '\0';
				} m++;
				k++;
			}
			n = 0;
			start = s;
		}
		i++;
	}

	char tmp[200];
	for (int x = 0; x < m - 1; x++) {
		for (int y = x + 1; y < m; y++) {
			int min_len = lesser_length(result[x], result[y]);
			for (int i = 0; i < min_len; i++)
			{
				if (result[x][i] > result[y][i])
				{
					strcpy(tmp, result[x]);
					strcpy(result[x], result[y]);
					strcpy(result[y], tmp);
					break;
				}
				else if (result[x][i] < result[y][i])
					break;
			}
		}
	}

	for (int t = 0; t < m; t++) {
		printf("%s ", result[t]);
		printf("\n");
	}

	getchar();
	return 0;
}