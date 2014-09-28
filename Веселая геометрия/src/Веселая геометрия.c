/*
 ============================================================================
 Name        : Веселая.c
 Author      : D.Linnik
 Version     :
 Copyright   : lol
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CFREE(x) {free(x); x =NULL;}		//Освобождение памяти

typedef struct Triangle {		//Описание треугольника
	float AB;
	float BC;
	float CA;
}Triangle;

void show_tr(Triangle * t)
{
	printf("Triangle: %.2f  %.2f  %.2f \n", t->AB, t->BC, t->CA);
}

Triangle * tr_init(float a, float b, float c)
{
	if(a + b < c || a + c < b || c + b < a)
	{
		printf("Wrong argumets: this is not a triangle");
		return NULL;
	}
	Triangle * t = malloc(sizeof(Triangle));
	if(!t)
	{
		printf("No available memory");
		return NULL;
	}
	t->AB = a;
	t->BC = b;
	t->CA = c;
	return t;
}

typedef struct Circle {			//Описание окружности
	float Rad;
}Circle;

void show_cir(Circle * c)
{
	printf("Circle: %.2f \n", c->Rad);
}

Circle * cir_init(float a)
{
	Circle * r = malloc(sizeof(Circle));
	if(!r)
	{
		printf("No available memory");
		return NULL;
	}
	r->Rad = a;
	return r;
}

typedef struct Square {			//Описание квадрата
	float AB;
}Square;

void show_sq(Square * s)
{
	printf("Square: %.2f", s->AB);
}

Square * sq_init(float a)
{
	Square * s = malloc(sizeof(Square));
	if(!s)
	{
		printf("No available memory");
		return NULL;
	}
	s->AB = a;
	return s;
}

Circle * circumcircle(Triangle * t)			//Функция нахождения описанной окружности
{
	float r = (t->AB * t->BC * t->CA) /
	sqrt((t->AB + t->BC + t->CA) * (-t->AB + t->BC +t->CA) * (t->AB - t->BC + t->CA) * (t->AB + t->BC - t->CA));
	Circle * c = cir_init(r);
	return c;
}

Square * squar(Circle * c)				//Функция нахождения описанного квадрата
{
	Square * s = sq_init(2*c->Rad);
	return s;
}

int main(void) {
	Triangle * t = tr_init(3.0, 3.0, 3.0);
	if(!t)
		return -1;
	show_tr(t);
	Circle * c = circumcircle(t);
	if(!c)
		return -1;
	show_cir(c);
	Square * s = squar(c);
	if(!s)
		return -1;
	show_sq(s);
	CFREE(t);
	CFREE(c);
	CFREE(s);
	return EXIT_SUCCESS;
}
