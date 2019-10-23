#include <stdio.h>
#include <stdlib.h>

void set_value(int **m, int row, int col, int k)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col ; j++)
		{
			int a = k + i+ j;
			m[i][j] = a;
		}
	}
}

void print_value(int **m, int row, int col)
{
	printf("생성된 행렬 : \n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", m[i][j]);
		}
		printf(" \n");
	}
	printf(" \n");
}

void add_values(int **m, int **n, int row, int col)
{
	printf("두 행렬을 합한 결과는 다음과 같습니다. : \n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", m[i][j] + n[i][j]);
		}
		printf(" \n");
	}
	printf(" \n");
}

void main()
{
	int row, col;

	printf("행렬의 행의 크기를 입력하시오. ");
	scanf("%d", &row);
	printf("행렬의 열의 크기를 입력하시오. ");
	scanf("%d", &col);
	

	int **a_array = malloc(sizeof(int *) * row);
	int **b_array = malloc(sizeof(int *) * col);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			a_array[i] = malloc(sizeof(int) *col);
			b_array[i] = malloc(sizeof(int) *col);
		}
	}

	set_value(a_array, row, col, 0);
	set_value(b_array, row, col, 1);

	print_value(a_array, row, col);
	print_value(b_array, row, col);

	add_values(a_array, b_array, row, col);

	for (int i = 0; i < row; i++)
	{
		free(a_array[i]);
		free(b_array[i]);
	}
	free(a_array);
	free(b_array);
}
