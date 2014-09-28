//============================================================================
// Name        : AVL.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

struct CNode {
    int Key;
    int Height;
    CNode* Left;
    CNode* Right;

    CNode(int key) : Key(key), Height(1),Left(0),Right(0) {}
};

int Height(CNode* p)
{
    return p == 0 ? 0 : p->Height;
}

int BalanceFactor(CNode* p)
{
    return Height(p->Left) - Height(p->Right);
}

CNode* RotateRight(CNode* p)
{
    CNode* q = p->Left;
    p->Left = q->Right;
    q->Right = p;
    p->Height = std::max(Height(p->Left), Height(p->Right)) + 1;
    q->Height = std::max(Height(q->Left), Height(q->Right)) + 1;
    return q;
}

CNode* RotateLeft(CNode* p)
{
    CNode* q = p->Right;
    p->Right = q->Left;
    q->Left = p;
    p->Height = std::max(Height(p->Left), Height(p->Right)) + 1;
    q->Height = std::max(Height(q->Left), Height(q->Right)) + 1;
    return q;
}

CNode* Balance(CNode* p)
{
    int balanceFactor = BalanceFactor(p);
    if(balanceFactor == -2) {
        if(BalanceFactor(p->Right) > 0) {
            p->Right = RotateRight(p->Right);
        }
        return RotateLeft(p);
    }
    if(balanceFactor == 2) {
        if(BalanceFactor(p->Left) < 0) {
            p->Left = RotateLeft(p->Left);
        }
        return RotateRight(p);
    }
    p->Height = std::max(Height(p->Left), Height(p->Right)) + 1;
    return p;
}

CNode* Insert(CNode* p, int key)
{
    if (p == 0) {
        return new CNode(key);
    }
    if (key < p->Key) {
        p->Left = Insert (p->Left, key);
    } else {
        p->Right = Insert (p->Right, key);
    }
    return Balance(p);
}

CNode* FindMin(CNode* p)
{
    return p->Left ? FindMin(p->Left) : p;
}

CNode* RemoveMin(CNode* p)
{
    if(p->Left == 0) {
        return p->Right;
    }
    p->Left = RemoveMin(p->Left);
    return Balance(p);

}

CNode* Delete(CNode* p, int key)
{
    if(!p) {
        return 0;
    }
    if (key < p->Key) {
        p->Left = Delete(p->Left, key);
    } else if (key > p->Key) {
        p->Right = Delete(p->Right, key);
    } else {
        CNode* q = p->Left;
        CNode* r = p->Right;
        delete p;
        if(!r) {
            return q;
        }
        CNode* min = FindMin(r);
        min->Right = RemoveMin(r);
        min->Left = q;
        return Balance(min);
    }
    return Balance(p);
}

void CNodeDelete(CNode* &node)
{
    if (node == NULL)
        return;
    CNodeDelete(node->Left);
    CNodeDelete(node->Right);
    delete(node);
}

int main()
{
    int k;
    CNode* root = 0;
    while (std::cin >> k) {
        if (k > 0) {
            root = Insert(root, k);
        }
        if (k < 0) {
            root = Delete(root, -k);
        }
    }
    std::cout << root->Height << std::endl;
    CNodeDelete(root);
    return 0;
}
