/*Пирог. Имеется прямоугольный пирог, разрезанный на m×n частей
(клеток), причем, левая нижняя клетка пирога отравлена. Игроки по
очереди выбирают какую-нибудь клетку пирога и «съедают» ее
вместе со всеми клетками, расположенными правее и выше
выбранной. Проигрывает тот, кто съедает отравленную клетку.*/

#include <stdio.h>
#include "main.h"

void Draw(int n, int m, int** Array)
{
    system("cls");
	printf("N - amount of lines, M - amount of columns. 0 - not eaten piece of cake, 1 - eaten, 2 - poisoned.\n\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d", Array[i][j]);
			printf("  ");
		}
		printf("\n");
	}
}

int Step(int string, int column, int** Array)
{
	if (Array[string][column] == 2)
	{
		return 2;
	}
	if (Array[string][column] != 1 && Array[string - 1][column] != 1 && Array[string][column + 1] != 1)
	{
		Array[string][column] = 1;
		Array[string - 1][column] = 1;			
		Array[string][column + 1] = 1;
		return 1;
	} else {
		return 0;
	}
}
int main()
{
	int n = 0, m = 0, column = 0, string = 0;
	printf("N - amount of lines, M - amount of columns. 0 - not eaten piece of cake, 1 - eaten, 2 - poisoned.\n\n");
	printf("Enter n: ");
	while (scanf("%d", &n) != 1 || n < 2) {
        printf("ERROR! Enter integer\n");
        while (getchar() != '\n') {}
    }
	printf("Enter m: ");
	while (scanf("%d", &m) != 1 || m < 2) {
        printf("ERROR! Enter integer\n");
        while (getchar() != '\n') {}
    }

	int** Array = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		Array[i] = (int*)malloc(m * sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			Array[i][k] = 0;
		}
	}
	Array[n - 1][0] = 2;

	while (1)
	{
		Draw(n, m, Array);
		printf("Select a column: ");
		while (scanf("%d", &column) != 1 || column < 0 || column >= (n - 1)) {
     	    printf("ERROR! Enter integer < N\n");
    		while (getchar() != '\n') {}
    	}
		printf("Select a line: ");
		while (scanf("%d", &string) != 1 || string <= 0 || string >= m) {
       		printf("ERROR! Enter integer < M\n");
       		while (getchar() != '\n') {}
    	}
		switch(Step(string, column, Array))
		{
			case 2:
				printf("You lose");
				for (int i = 0; i < n; i++)
				{
					free(Array[i]);
				}
				free(Array);
				return 0;
				break;
			case 0:
				printf("A piece has already been eaten, choose another\n");
				break;
			default: break;
		}
	}	
}