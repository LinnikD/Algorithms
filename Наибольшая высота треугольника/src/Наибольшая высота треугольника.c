/*
 ============================================================================
 Name        : Наибольшая.c
 Author      : D.Linnik
 Version     :
 Copyright   : lol
 Description : Посчитушки с треугольничком
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//подключение библиотеки с функцие возведения числа в степень
#include <math.h>

//Макрос для корректного использования функции free()
#define CFREE(x) { if (x){ free(x); x=NULL; printf("\n correct\n");} else{printf("\n error\n");}}

//Вспомогательньная функция вычисления расстояния между точками A(x,y) и B(x,y)
double length(double * pfxa, double * pfya, double * pfxb, double * pfyb)
{
	double tmp = pow(*pfxa-*pfxb,2) + pow(*pfya-*pfyb,2);
	return pow(tmp , 0.5);
}

//Функция вычисления наибольшей высоты треугольника A(x,y), B(x,y) и C(x,y)
double * findmaxh(double * pfxa, double * pfya, double * pfxb, double * pfyb, double * pfxc,double * pfyc)
{
	double * phmax=NULL;

	//Динамическое выделение памяти для высоты  !!!Не забыть очистить память!!!
	phmax=(double*)malloc(sizeof(double));

	//Проверка указателя
	if(phmax==NULL)
	{
		printf("\n Error with pointer\n");
		exit(0);
	}
	//Вызов вспомогательных функций для вычисления сторон треугольника
	double AB=length(pfxa,pfya,pfxb,pfyb);
	double BC=length(pfxb,pfyb,pfxc,pfyc);
	double AC=length(pfxa,pfya,pfxc,pfyc);

	//Вычисление полупириметра (Вспомогательная переменная)
	double p=(AB+BC+AC)/2;
	//Вычисление площади треугольника (Вспомогательная перменная)
	double s=pow(p*(p-AB)*(p-BC)*(p-AC),0.5);

	//Проверка существования треугольника
	if(s<=0)
	{
		CFREE(phmax);
		printf("This is not triangle, please, try again later.");
		return NULL;
	}

	//Условия нахождения наибольшей высоты.
	if((AB<=BC) && (AB<=AC))    // AB наименьшая сторона?
	{
		*phmax=2*s/AB;
	}
	else
	{
		if(BC<=AC)             // А может BC наименьшая?
		{
			*phmax=2*s/BC;
		}
		else					// тогда AC
		{
			*phmax=2*s/AC;
		}
	}
	return phmax;				//Вернуть указатель
}

int main(void)
{
	//объявление и инициализация координат точек
	double xa=0;
	double ya=12;
	double xb=4;
	double yb=0;
	double xc=-4;
	double yc=0;

	//объявление и инициализация ссылок на координаты
	double *pxa=&xa;
	double *pxb=&xb;
	double *pxc=&xc;
	double *pya=&ya;
	double *pyb=&yb;
	double *pyc=&yc;

	//Объявление указателя и его инициализация функцией, возвращающей указатель
	double * c=findmaxh(pxa,pya,pxb,pyb,pxc,pyc);

	//Печать результата
	if(c!=NULL)
	{
		printf("%f", *c);
	}
	else
	{
		printf("\n Error with pointer\n");
	}
	//Освобождение динамически выделенной памяти
	CFREE(c);

	return 0;
}
