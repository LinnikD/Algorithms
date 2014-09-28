//============================================================================
// Name        : Солдатики.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stack>
#include <iostream>

using namespace std;

struct CNode {
	int key_;
	int height_;
	int volume_;
	CNode* right_;
	CNode* left_;

	CNode (int _key) : key_ (_key), height_ (1), volume_ (1), right_ (0), left_ (0) {}
};

int height(CNode* _node) {
	return _node == 0 ? 0 : _node->height_;
}

int volume(CNode* _node) {
	return _node == 0 ? 0 : _node->volume_;
}

int balance_factor(CNode* _node) {
	return height(_node->right_) - height(_node->left_);
}

CNode* rotate_right(CNode* _root) {
	CNode* q = _root->left_;
	_root->left_ = q->right_;
	q->right_ = _root;

	_root->height_ = std::max(height(_root->left_), height(_root->right_)) + 1;
	q->height_ = std::max(height(q->left_), height(q->right_)) + 1;

	_root->volume_ = volume(_root->left_) + volume(_root->right_) + 1;
	q->volume_ = volume(q->left_) + volume(q->right_) + 1;

	return q;
}

CNode* rotate_left(CNode* _root) {
	CNode* p = _root->right_;
	_root->right_ = p->left_;
	p->left_ = _root;

	_root->height_ = std::max(height(_root->left_), height(_root->right_)) + 1;
	p->height_ = std::max(height(p->left_), height(p->right_)) + 1;

	_root->volume_ = volume(_root->left_) + volume(_root->right_) + 1;
	p->volume_ = volume(p->left_) + volume(p->right_) + 1;

	return p;
}

CNode* balance(CNode* _root) {
	int b = balance_factor(_root);
	if (b == 2) {
		if (balance_factor(_root->right_) < 0)
			_root->right_ = rotate_right(_root->right_);
		return rotate_left(_root);
	}

	if (b == -2) {
		if (balance_factor(_root->left_) > 0)
			_root->left_ = rotate_left(_root->left_);
		return rotate_right(_root);
	}

	_root->height_ = std::max(height(_root->left_), height(_root->right_)) + 1;
	_root->volume_ = volume(_root->left_) + volume(_root->right_) + 1;

	return _root;
}

CNode* insert(CNode* _root, int key, int num) {
	if (_root == 0) {
		cout<< num <<'\n';
		return new CNode(key);
	}

	if (key < _root->key_) {
		num += volume(_root->right_) + 1;
		_root->left_ = insert(_root->left_, key, num);
	}
	else
		_root->right_ = insert(_root->right_, key, num);

	return balance(_root);
}

CNode* find_min(CNode* _root) {
	return (_root->left_ == 0) ? _root : find_min(_root->left_);
}

CNode* remove_min(CNode* _root) {
	if (_root->left_ == 0)
		return _root->right_;

	_root->left_ = remove_min(_root->left_);

	return balance(_root);
}

void delete_node(CNode* _node) {
	if (_node == 0)
		return;

	delete_node(_node->right_);
	delete_node(_node->left_);

	delete _node;
}

CNode* remove(CNode* _root, int _num) {
	if (_root == 0 || _num > volume(_root))
		 return 0;

	int cur = volume(_root->right_) + 1;

	if (_num == cur) {
		CNode* l = _root->left_;
		CNode* r = _root->right_;
		delete _root;

		if (r == 0)
			return l;

		CNode* min = find_min(r);
		min->right_ = remove_min(r);
		min->left_ = l;

		return balance(min);
	}
	else if (_num < cur)
		_root->right_ = remove(_root->right_, _num);
	else
		_root->left_ = remove(_root->left_, _num - cur);

	return balance(_root);
}

int main() {
	CNode* root = 0;

	int n, comm, a;
	cin>>n;

	for (int i = 0; i < n; ++i) {
		cin>>comm>>a;
		if (comm == 1)
			root = insert(root, a, 0);
		else
			root = remove(root, a + 1);
	}

	delete_node(root);

	return 0;
}
