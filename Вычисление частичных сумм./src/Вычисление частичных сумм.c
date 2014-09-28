/*
 ============================================================================
 Name        : Вычисление.c
 Author      : D.Linnik
 Version     :
 Copyright   : lol
 Description : Ряды такие ряды
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
//Объявление размера входного массива
#define LENGTH 15

//Макрос для корректного использования функции free()
#define CFREE(x) { if (x){ free(x); x=NULL; printf("\n correct\n");} else{printf("\n error\n");}}

//Глобальная вспомогательная переменная
size_t i;


//Функция подсчета частичных сумм массива
double * sums(double * pA,int len)
{
	//Проверка правильности ввода исходных данных
	if((pA==NULL) || len<0)
	{
		printf("Error in function");
		exit(1);
	}
	extern size_t i;		//явное объявление переменной(избыточно)
	double * newA=NULL;		//Возвращаемый массив
	double tmpsum=0;	//вспомогательная переменная
	newA=(double*)malloc(len*sizeof(double));

	//Проверка указателя
	if(newA==NULL)
	{
		CFREE(newA);
		exit(0);
	}

	//Цикл подсчета частичных сумм
	for(i=0;i<len;i++)
	{
		tmpsum+=*(pA+i);
		*(newA+i)=tmpsum;
	}
	return newA;
}


int main(void)
{
	int i=0;			//явное определение (избыточно)

	// исходный массив(выделенные инициализаторы)
	double Arr[LENGTH]={17, 22, [6]=3, 44, 55, [12]=55, 31};

	double *pArr=&Arr[0];

	//вывод входных данных
	printf("input:\n");
	for(i=0;i<LENGTH;i++)
	{
		printf("%7.2f ",*(pArr+i));		//Исользование арифметики указателей
	}
	printf("\n");

	//Вызов функции подсчета частичных сумм
	double* Result=sums(pArr,LENGTH);

	//Вывод частичных сумм
	printf("output:\n");
	for(i=0;i<LENGTH;i++)
	{
		printf("%7.2f ",*(Result+i));
	}

	//Освобождение динамически выделенной памяти
	CFREE(Result);

	return EXIT_SUCCESS;
}
