//============================================================================
// Name        : Минимальное.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

static void Heapify(int _arr[], int _top, int _size) {
	int left = 2 * _top + 1;
	int rigth = 2 * _top + 2;

	int lowest = _top;
	if (left < _size && _arr[left] < _arr[_top])
		lowest = left;

	if (rigth < _size && _arr[rigth] < _arr[lowest])
		lowest = rigth;

	if (lowest != _top) {
		swap(_arr[_top], _arr[lowest]);
		Heapify(_arr, lowest, _size);
	}
}

static void buildMinHeap(int _arr[], int _size) {
	for (int i = (_size - 1) / 2; i >= 0; i--)
		Heapify(_arr, i, _size);
}

static void Extract(int _arr[], int top, int _size) {
	swap(_arr[0], _arr[_size-1]);
	Heapify(_arr, top, _size - 1);
	Heapify(_arr, 0, _size - 1);
}

static int calc(int _arr[], int _size) {
	int time = 0;
	int cnt = 0;

	buildMinHeap(_arr, _size);

	while (cnt < _size - 1) {
		int sum = 0;
		if (_arr[1] > _arr[2] && _size - cnt > 2) {
			sum = _arr[0] + _arr[2];
			_arr[2] = sum;
			Extract(_arr, 2, _size - cnt);
		}
		else {
			sum = _arr[0] + _arr[1];
			_arr[1] = sum;
			Extract(_arr, 1, _size - cnt);
		}
		time += sum;
		cnt++;
	}
	return time;
}


int main() {

	int n;
		cin>>n;

		int arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];

		cout<<calc(arr,n);

		return 0;
}
