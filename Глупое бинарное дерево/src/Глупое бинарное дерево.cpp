//============================================================================
// Name        : Глупое.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

class CNode {
public:
	long int a;
	CNode * lh;
	CNode * rh;
	CNode(long int val):a(val) {
		lh = NULL;
		rh = NULL;
	}
};

typedef CNode* PCNode;
void Insert( PCNode& node, int value )
{
    if( node == NULL ) {
        node = new CNode( value );
        return;
    }
    if( node->a > value )
        Insert( node->lh, value );
    else
        Insert( node->rh, value );
};

void TraverseBFS( CNode* root )
{
    queue<CNode*> q;
    q.push( root );
    while( !q.empty() ) {
    	CNode* node = q.front();
        q.pop();
        cout<< node->a<<' ';
        if( node->lh != NULL )
            q.push( node->lh );
        if( node->rh != NULL )
            q.push( node->rh );
        delete node;
    }
};

int main() {
	int n;
	long int tmp;
	cin>>n;
	cin>>tmp;
	CNode * head = new CNode(tmp);
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		Insert(head, tmp);
	}
	TraverseBFS( head );
	return 0;
}
