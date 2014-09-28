//============================================================================
// Name        : Hash.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================
#define a 50000
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

size_t hash1(const string& data, size_t maxSize)
{
	  size_t value = 0;
	  for (size_t i = 0; i < data.size(); ++i) {
	    value += data[i] * 1009;
	  }
	  return value;
}

size_t hash2(const string& data, size_t maxSize)
{
	  size_t value = 0;
	  for (size_t i = 0; i < data.size(); ++i) {
	    value += data[i] * 17;
	  }
	  return value;
}

enum State { EMPTY=0, ACTIVE, DELETED };

class CHashNode {
    public:
        string value;
        State state;
        CHashNode(const string & s, State st) : value(s), state(st) {}
        CHashNode() : state(EMPTY) {}
};

class CHashTable {
    public:
        bool Add(const string&);
        bool Delete(const string&);
        bool Contains(const string& s) {
        	return table[findPos(s)].state == ACTIVE;
        }
        CHashTable(size_t size = a) : table(size), cSize(0) {}
    private:
        int findPos(const string &);
        int findPosAdd(const string & s);
        vector<CHashNode> table;
        void rehash();
        size_t cSize;
};

void CHashTable::rehash() {
    vector<CHashNode> old_table = table;
    table.resize(3 * table.size());
    cSize = 0;
    for(size_t i = 0; i < table.size(); ++i)
    	table[i].state = EMPTY;
    for(size_t i = 0; i < old_table.size(); ++i) {
        if(old_table[i].state == ACTIVE) {
            Add(old_table[i].value);
        }
    }
}

int CHashTable::findPos(const string & s) {
	int current_pos = hash1(s,table.size()) % table.size();
	while(table[current_pos].state != EMPTY && table[current_pos].value != s) {
		current_pos += hash2(s,table.size());
		current_pos %= table.size();
	}
    return current_pos;
}

int CHashTable::findPosAdd(const string & s) {
	int current_pos = hash1(s,table.size()) % table.size();
	while(table[current_pos].state == ACTIVE && table[current_pos].value != s) {
		current_pos += hash2(s,table.size());
		current_pos %= table.size();
	}
    return current_pos;
}

bool CHashTable::Add(const string& val) {
    int pos = findPosAdd(val);
    if(table[pos].state == ACTIVE)
    	return false;
    table[pos] = CHashNode(val, ACTIVE);
    cSize++;
    if(cSize * 2 > table.size() )
    	rehash();
    return true;
}

bool CHashTable::Delete(const string& s) {
    int pos = findPos(s);
    if(table[pos].state != ACTIVE)
    	return false;
    table[pos].state = DELETED;
    return true;
}

int main() {
    CHashTable t;
    char cmd;
    string val;
    while(cin >> cmd >> val) {
        if(!cin.eof()) {
				if(cmd == '+') cout << (t.Add(val) ? "OK\n" : "FAIL\n");
			else
				if(cmd == '-') cout << (t.Delete(val) ? "OK\n" : "FAIL\n");
			else
				cout << (t.Contains(val) ? "OK\n" : "FAIL\n");
			}
        else
        	break;
    }
	return 0;
}
