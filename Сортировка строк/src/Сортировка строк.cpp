//============================================================================
// Name        : Сортировка.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void read_data(vector<string> *n) {
	string a;
	while(getline(cin,a))
		n->push_back(a);
}

void print_data(vector<string> *n)
{
	size_t k = n->size();
	for(size_t i = 0; i < k ;)
	{
		cout<<n->at(i++)<<'\n';
	}
}

void string_insert_sort(vector<string> *n)
{
	int j, k = n->size();
	string tmp;
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
	vector<string> num;
	read_data(&num);
	string_insert_sort(&num);
	print_data(&num);
	return 0;
}
