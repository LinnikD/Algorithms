/*
 ============================================================================
 Name        : Совпадение.c
 Author      : D.Linnik
 Version     :
 Copyright   : lol
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int Check(int * pA, int * pB, int lenA, int lenB) {
	int count = 0;
	int j = 0;
	int i = 0;
	while((i < lenA) && (j < lenB)) {
		if (*(pA+i) == *(pB+j)) {
		i++;
		j++;
		count++;
		continue;
		}
		if (*(pA+i) < *(pB+j)) {
			i++;
			continue;
		}
		if (*(pA+i) > *(pB+j)) {
			j++;
			continue;
		}
	}
	return count;
}

int main(void) {
	int n=0;
	scanf("%d",&n);
	int *A=NULL;
	A=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++) {
		scanf("%d", (A+i));
	}
	int m=0;
	scanf("%d",&m);
	int *B=NULL;
	B=(int*)malloc(m*sizeof(int));
	for(int i=0;i<m;i++) {
		scanf("%d", (B+i));
	}
	int c = Check(A,B,n,m);
	printf("%d", c);
	free(A);
	free(B);
	return EXIT_SUCCESS;
}
