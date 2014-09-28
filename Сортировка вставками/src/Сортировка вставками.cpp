//============================================================================
// Name        : Сортировка.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

void read_data(vector<long int> *n) {
	long int a;
	while(cin>>a)
	{
		if(!cin.eof())
		n->push_back(a);
		else
		break;
	}
}

void print_data(vector<long int> *n)
{
	size_t k = n->size();
	for(size_t i = 0; i < k ;)
	{
		cout<<n->at(i++)<<'\n';
	}
}

void insert_sort(vector<long int> *n)
{
	int j, k = n->size();
	long int tmp;
	for(int i = 0; i < k;i++)
	{
		j = i;
		while(j>0 && n->at(j) < n->at(j-1))
		{
			tmp = n->at(j);
			n->at(j) = n->at(j-1);
			n->at(j-1) =tmp;
			--j;
		}
	}
}

int main() {
	vector<long int> num;
	read_data(&num);
	insert_sort(&num);
	print_data(&num);
	return 0;
}
