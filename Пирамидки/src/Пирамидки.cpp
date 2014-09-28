//============================================================================
// Name        : Пирамидки.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;



int main() {
	long int n;
	cin >> n;
	long int **a = new long int*[n + 1];
	for( int i = 0; i < n + 1; i++ ) {
		a[i] = new long int[n + 1];
	}
	 for (int cubes = 1; cubes <= n; cubes++)
		 a[cubes][0] = 0 ;
	 for (int width = 0; width <= n; width++)
	     a[0][width] = 1;
	 for (int cubes = 1; cubes <= n; cubes++) {
	    for (int width = 1; width <= cubes; width++)
	        a[cubes][width] = a[cubes][width - 1] + a[cubes - width][width];
	    for (int width = cubes+1; width <= n; width++)
	        a[cubes][width] = a[cubes][cubes];
	}
	cout<<a[n][n];
	for( int i = 0; i < n; i++ ) {
		delete[] a[i];
	}
	delete[] a;
	return 0;
}
