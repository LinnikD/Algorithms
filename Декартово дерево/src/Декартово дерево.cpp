//============================================================================
// Name        : Декартово.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

class CTreapNode {
public:
    int Key;
    int Priority;
    CTreapNode* Left;
    CTreapNode* Right;
    CTreapNode(int key, int priority) : Key(key), Priority(priority), Left(0), Right(0) {}
    CTreapNode(int key) : Key(key), Priority(0), Left(0), Right(0) {}
};


typedef CTreapNode* PCNode;

void Insert( PCNode& node, int value )
{
    if( node == NULL ) {
        node = new CTreapNode( value );
        return;
    }
    if( node->Key > value )
        Insert( node->Left, value );
    else
        Insert( node->Right, value );
}

CTreapNode* Merge(CTreapNode* left, CTreapNode* right)
{
        if( left == 0 || right == 0 ) {
                return left == 0 ? right : left;
        }
        if( left->Priority > right->Priority ) {
                left->Right = Merge(left->Right, right);
                return left;
    }
        right->Left = Merge(left, right->Left);
        return right;
}

void Split(CTreapNode* currentNode, int key, CTreapNode*& left, CTreapNode*& right)
{
        if( currentNode == 0 ) {
                left = 0;
                right = 0;
        } else if( currentNode->Key <= key ) {
                CTreapNode* tempLeft = 0;
                CTreapNode* tempRight = 0;
                Split(currentNode->Right, key, tempLeft, tempRight);
                right = tempRight;
                left = currentNode;
                left->Right = tempLeft;
    } else {
                CTreapNode* tempLeft = 0;
                CTreapNode* tempRight = 0;
                Split(currentNode->Left, key, tempLeft, tempRight);
                left = tempLeft;
                right = currentNode;
                right->Left = tempRight;
    }
}

CTreapNode* Insert(CTreapNode* root, int key, int priority) {
        CTreapNode* node = new CTreapNode(key, priority);
        CTreapNode* splitLeft = 0;
        CTreapNode* splitRight = 0;
        Split(root, key, splitLeft, splitRight);
    return Merge(Merge(splitLeft, node), splitRight);
}

int TraverseBFS( CTreapNode* root )
{
	int counter = 0;
	int result = 0;
    queue<CTreapNode*> q;
    q.push( root );
    q.push( NULL );
    while( !q.empty() ) {
    	if(q.front() == NULL) {
    		result = max(counter , result);
    		counter = 0;
    	//	cout<<'\n';
    		q.pop();
    		q.push( NULL );
    	}
    	if(q.size()==1)
    		return result;
    	counter++;
    	CTreapNode* node = q.front();
        q.pop();
        //   cout<< node->Key<<' ';
        if( node->Left != NULL )
            q.push( node->Left );
        if( node->Right != NULL )
            q.push( node->Right );
        delete node;
    }
return result;
};

int main() {
	int n, val, pri;
	cin >> n;
	CTreapNode * dataT, * data;
	dataT = data = NULL;
	for( int i = 0; i < n; i++ ) {
		cin >> val >> pri;
		dataT = Insert(dataT, val, pri);
		Insert(data, val);
	}
	cout<< TraverseBFS( dataT ) - TraverseBFS( data );
	return 0;
}
