//============================================================================
// Name        : Пресечение.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void cross(float a[], float b[], int n, int m) {
    int i, first = 0, mid, last;

    for (i = 0; i < m; i++) {
        last = n;
        while (first < last) {
            mid = first + (last - first) / 2;
            if (b[i] <= a[mid])
                last = mid;
            else
                first = mid + 1;
        }
        if (b[i] == a[first]) {
            cout << a[first++] << " ";
        }
    }
    cout << endl;
}

int main() {
	int n, m, i;
	    cin >> n >> m;
	    float a[n], b[m];
	    for (i = 0; i < n; i++)
	        cin >> a[i];
	    for (i = 0; i < m; i++)
	        cin >> b[i];
	    cross(a, b, n, m);
	return 0;
}

