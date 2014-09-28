//============================================================================
// Name        : Quikest.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


int mediana(int*data, int lb, int ub) {
	int med;
	med = (lb + ub)>> 1;
	if(data[lb] > data[ub]) {
		if(data[med] > data [lb])
			return lb;
		if(data[med] < data[ub])
			return ub;
		return med;
	}
	else {
		if(data[med] > data[ub])
			return ub;
		if(data[med] < data[lb])
			return lb;
		return med;
	}
}

int read_data(int *n) {
	int a, i = 0;
	while(cin>>a)
	{
		if(!cin.eof())
			n[i] = a;
		else
			break;
		++i;
	}
	return i;
}

void print_data(int *n, int size)
{
	for(int i = 9; i < size ; i += 10)
	{
		cout<<n[i]<<' ';
	}
}

#define MAXSTACK 2048		// максимальный размер стека

void qSort(int * a, int size) {

  int i, j;   			// указатели, участвующие в разделении

  int lb, ub;  		// границы сортируемого в цикле фрагмента

  int lbstack[MAXSTACK], ubstack[MAXSTACK]; // стек запросов
                        // каждый запрос задается парой значений,
                        // а именно: левой(lbstack) и правой(ubstack)
                        // границами промежутка

  int stackpos = 1;   	// текущая позиция стека
  int ppos;            // середина массива
  int pivot;              // опорный элемент
  int temp;

  lbstack[1] = 0;
  ubstack[1] = size-1;

  do {

    // Взять границы lb и ub текущего массива из стека.

    lb = lbstack[ stackpos ];
    ub = ubstack[ stackpos ];
    stackpos--;

    do {
      // Шаг 1. Разделение по элементу pivot

      ppos = mediana(a,lb,ub);
      i = lb; j = ub; pivot = a[ppos];

      do {
        while ( a[i] < pivot ) i++;
        while ( pivot < a[j] ) j--;

        if ( i <= j ) {
          temp = a[i]; a[i] = a[j]; a[j] = temp;
          i++; j--;
        }
      } while ( i <= j );

      // Сейчас указатель i указывает на начало правого подмассива,
      // j - на конец левого (см. иллюстрацию выше), lb ? j ? i ? ub.
      // Возможен случай, когда указатель i или j выходит за границу массива

      // Шаги 2, 3. Отправляем большую часть в стек  и двигаем lb,ub

      if ( i < ppos ) {     // правая часть больше

        if ( i < ub ) {     //  если в ней больше 1 элемента - нужно
          stackpos++;       //  сортировать, запрос в стек
          lbstack[ stackpos ] = i;
          ubstack[ stackpos ] = ub;
        }
        ub = j;             //  следующая итерация разделения
                            //  будет работать с левой частью

      } else {       	    // левая часть больше

        if ( j > lb ) {
          stackpos++;
          lbstack[ stackpos ] = lb;
          ubstack[ stackpos ] = j;
        }
        lb = i;
      }

    } while ( lb < ub );        // пока в меньшей части более 1 элемента

  } while ( stackpos != 0 );    // пока есть запросы в стеке
}

int num[25000000];

int main() {

	int n = read_data(num);
	qSort(num, n);
	print_data(num, n);
	return 0;
}
