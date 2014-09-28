//============================================================================
// Name        : Переговоры.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int a,b;
	vector< pair<int, int> > data;
	while(cin>>a>>b) {
		if(!cin.eof()) {
			data.push_back(pair<int,int>(b,a));
		}
		else
			break;
	}
	sort(data.begin(), data.end());
	int ans = 1;
	int cur = 0;
	for(size_t i = 1; i < data.size(); ++i) {
		if(data[cur].first <= data[i].second) {
			ans++;
			cur = i;
		}
	}
	cout<< ans;
	return 0;
}
