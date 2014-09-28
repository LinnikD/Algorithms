//============================================================================
// Name        : Поиск.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int partition(long int * data, int l, int r)
{
	int p = rand()%(r-l+1) + l;
	swap(data[r], data[p]);
	int i = l;
	int j = l;
	while(j != r)
	{
		if(data[j] > data[r])
		{
			j++;
		}
		else
		{
			swap(data[j],data[i]);
			i++;
			j++;
		}
	}
	swap(data[i], data[r]);
	return i;
}

int findKstatistics(long int * data, int l, int r, int k)
{
	while (true)
	{
		int q = partition(data, l , r);
		if(q==k)
			return data[k];
		if(q < k)
			l = q+1;
		if(q > k)
			r = q-1;
	}
	return 666;
}


int main() {
	long int n, k;
	cin>>n;
	cin>>k;
	long int* data = new long int[n];
	for(long int i=0; i<n; i++) {
		cin>>*(data+i);
	}
	cout<<findKstatistics(data, 0, n-1, k);
	return 0;
}
