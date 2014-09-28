/*
 ============================================================================
 Name        : Перевод.c
 Author      : D.Linnik
 Version     :
 Copyright   : lol
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void TranslateSystem(int n,int m)
{
	int tmp = 0;
	int i=0;
	int chArr[15];
	while(n != 0)
	{
		tmp = n % m;
		if (tmp <= 9)
		{
			chArr[i] = (tmp + 48);
		}

		else
		{
			chArr[i] = (tmp + 55);
		}
		n /= m;
		i++;
	}

	for(int j = 1; j <= i; j++)
	{
		printf("%c", chArr[i - j]);
	}
}

int main(void) {
	int x;
	scanf("%d",&x);
	int y;
	scanf("%d",&y);
	TranslateSystem(x,y);
	return EXIT_SUCCESS;
}
