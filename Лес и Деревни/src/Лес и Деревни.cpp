//============================================================================
// Name        : Лес.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;



int main() {
	int n;
	cin >> n;
	int * Data = new int[n];
	for(int i = 0; i < n; i++)
		cin>>Data[i];
	sort(Data, Data+n);
	if( n > 2 ) {
		int Length = *(Data + 2) - *Data;
		int LenPrev = *(Data + 1) - *Data;
		int LenNext = 0;
		for(int i = 2; i < n - 1; i++) {
			LenNext = min( Length + (Data[i+1] - Data[i]) , LenPrev + (Data[i+1] - Data[i]));
			LenPrev = Length;
			Length = LenNext;
		}
		cout<<Length;
	}
	else
		if( n == 2 )
			cout<<*(Data+1) - *Data;
		else
			cout << 0;

	return 0;
}
