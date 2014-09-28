/*
 ============================================================================
 Name        : Пересечение.c
 Author      : D.Linnik
 Version     :
 Copyright   : lol
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int i=0;

void findext(int* A,int n, int* B, int m)
{
	int k = 0;
	int i = 0;
	int begin = 0;
	int end = n - 1;
	begin = 0;
	for(i = 0;i < m;i++)
	{
		k = 0;
		end = n - 1;
		  do
		  {
			  k = (end + begin) / 2;
			  if(*(A + k) < *(B + i))
			  {
				  begin = ++k;
			  }
			  if(*(A + k) > *(B + i))
			  {
				  end = k;
			  }
			  if(*(A + k) == *(B + i))
			  {
				  printf("%d ", *(B + i));
				  break;
			  }
		  }
		  while((end - begin) > 0);
		  begin+=(end - begin);
	}
}

int main(void) {
	int n=0;
	scanf("%d", &n);
	int m=0;
	scanf("%d", &m);
	int *A = NULL;
	A = (int*)malloc(n*sizeof(int));
	for(i = 0;i < n;i++)
	{
		scanf("%d", (A+i));
	}
	int *B = NULL;
	B=(int*)malloc(m*sizeof(int));
	for(i = 0;i < m;i++)
	{
		scanf("%d", (B+i));
	}
	findext(A,n,B,m);
	free(A);
	free(B);
	return EXIT_SUCCESS;
}
