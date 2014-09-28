//============================================================================
// Name        : Sort.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void merge(int * data1, int * data2, int k, int m) {
	int i = 0;
	int j = 0;
	int tmp[k];
	while( i + j < k) {
		if(j < m) {
			if(data1[i] <= data2[j]) {
				tmp[i + j] = data1[i];
				++i;
			}
			else {
				tmp[i + j] = data2[j];
				++j;
			}
		}
		else {
			tmp[i + j] = data1[i];
			++i;
		}
	}
	for(i = 0; i < k; i++) {
		data1[i] = tmp [i];
	}
}

void quick_sort (int *a, int n) {
	int i = 0;
	int j = n - 1;
	bool side = 0;
	while (i != j) {
		if ( a[i] > a[j] ) {
			swap(a[i], a[j]);
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

void sort_first_k(int * data,int n, int * res, int k) {
	quick_sort(data, k);
	for(int i = 0; i < k; i++) {
		res[i] = data [i];
	}
	long long j = 0;
	for(int i = 1; i < n/k ;i++ ) {
		j = k * i;
		quick_sort(&data[j], k);
		merge(res, &data[j], k, k);
	}
	if(n%k != 0) {
		j+=k;
		quick_sort(&data[j], (n - j));
		merge(res,&data[j], k, (n - j));
	}
}

int main() {
	long long n;
	cin>>n;
	int k;
	cin>>k;
	int *data = new int[n];
	for(long long i = 0; i < n; i++) {
		cin>>data[i];
	}
	int *result = new int[k];
	sort_first_k(data, n, result, k);
	for(int i =0; i < k; i++)
	{
		cout<<result[i]<<" ";
	}
	delete[] data;
	delete[] result;
	return 0;

}
