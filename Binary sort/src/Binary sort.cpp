//============================================================================
// Name        : Binary.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int digit(long long t, int w) {
	long long tmp = 1;
	tmp <<= 64 - w;
	tmp &= t;
	if(tmp == 0)
		return 0;
	else
		return 1;
}

void binaryquick(long long * d, int n, int l, int r, int w) {
	int i = l;
	int j = r;
	if(r <= l || w > 64)
		return;
	while(j != i) {
		while(digit(d[i], w) == 0 && i < j)
			i++;
		while(digit(d[j],w) == 1 && j > i)
			j--;
		swap(d[i], d[j]);
	}
	if(digit(d[r], w) == 0)
		j++;
	binaryquick(d, n, l, j-1, w+1);
	binaryquick(d, n, j, r, w+1);
}

int main() {
	int n = 0;
	cin>>n;
	long long * data = new long long[n];
	for(int i = 0; i < n; i++) {
		cin>>data[i];
	}
	binaryquick(data, n, 0, n-1, 1);
	for(int i =0; i < n; i++) {
		cout<<data[i]<<" ";
	}
	return 0;
}
