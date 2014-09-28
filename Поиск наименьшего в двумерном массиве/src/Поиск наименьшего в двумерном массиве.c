/*
 ============================================================================
 Name        : Поиск.c
 Author      : D.Linnik
 Version     :
 Copyright   : lol
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>

ptrdiff_t nul = NULL;

#define LENGTH 5
#define HEIGHT 5

#define CFREE(x) {free(x); x = NULL;}  // Обнуление указателя после освобождения памяти

int* init_arr(int n)			// Вспомогательная функция случайного заполнения массива
{
	int * A = (int*)malloc(n*sizeof(int));
	if(A==NULL)
	{
		printf("Memory error");
		return NULL;
	}
	for(int i = 0;i < n;i++)
	{
		*(A + i) = rand()%10;
	}
	return A;
}

void print_arr(int *restrict A,int n, int m)		// Вспомогательная функция печати двумерного массива
{
	if(A!=NULL)
	{
	for(int i = 0; i < m; i++)
	{
		for(int j=0; j < n; j++)
		{
			printf("%d ", *(A+j+m*i));
		}
	printf("\n");
	}
	printf("\n");
	}
	else
	{
		printf("Empty pointer");
	}
}


int * find_min(int * restrict A, int n, int m)
{
	if(A != NULL)	//Проверка корректности выделения памяти
	{
		int tmp;
		int * restrict B = (int*)malloc(m*sizeof(int));
		if(B == NULL)
		{
			printf("Memory error");
			return NULL;
		}
		for(int i = 0; i < m; i++)
		{
			if(i > 0)
			{
				tmp = *(A + m * i);
			}
			else
			{
				tmp = *(A + 1);
			}
			for(int j = 0; j < n; j++)
			{
				if(i==j)
				{
					continue;
				}
				if(tmp > *(A + m * i + j))
				{
					tmp = *(A + m * i + j);
				}
			}
			*(B + i) = tmp;
		}
		return B;
	}
	else
	{
		printf("Empty pointer");
		return NULL;
	}
}

int main(void) {
	srand(time(NULL));
	int * Arr = init_arr(LENGTH*HEIGHT);
	print_arr(Arr, LENGTH, HEIGHT);
	int* c = find_min(Arr,LENGTH, HEIGHT);
	print_arr(c, HEIGHT, 1);
	CFREE(c);
	CFREE(Arr);
	return EXIT_SUCCESS;
}
