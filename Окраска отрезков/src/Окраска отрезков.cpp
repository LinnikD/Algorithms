//============================================================================
// Name        : Окраска.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

struct coord {
	int x;
	int flag;
};

void quick_sort (coord *a, int n) {
	int i = 0;
	int j = n - 1;
	bool side = 0;
	while (i != j) {
		if ( a[i].x > a[j].x ) {
			coord temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			side =!side;
		}
		if (side) {
			++i;
		} else {
			--j;
		}
	}
	if (i > 1)
		quick_sort(a, i);
	if (n > (i + 1))
		quick_sort(a + (i + 1), n - (i + 1));
}

int one_len(coord *a, int n) {
	int i = 0, sum = 0, count = 0;
	quick_sort(a, n);
    for (i = 0; i < n - 1; ++i) {
    	count += a[i].flag;
    	if ( count == 1) {
    		sum += a[i + 1].x - a[i].x;
    	}
    }
	return sum;
}

int main() {
	int n = 0, i = 0, k = 0;
	cin>>n;
	n = n * 2;
	coord a[n];
	for (i = 0; i < n / 2; i++) {
		cin >> a[2 * i].x >> a[2 * i + 1].x;
		a[2 * i].flag = 1;
		a[2 * i + 1].flag = -1;
	}
	k = one_len(a, n);
	cout<<k;
	return 0;
}
