/*
 ============================================================================
 Name        : Число.c
 Author      : D.Linnik
 Version     :
 Copyright   : lol
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int counter(int n)
{
	int count = 0;
	while(n != 0)
	{
		if(n % 2 != 0)
		{
			count++;
		}
		n=n/2;
	}
	return count;
}

int main(void) {
	int num = 0;
	scanf("%d",&num);
	int k = counter(num);
	printf("\n %d \n",k);
	return EXIT_SUCCESS;
}
