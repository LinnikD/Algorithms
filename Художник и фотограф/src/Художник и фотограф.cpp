//============================================================================
// Name        : Художник.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <climits>

class CSegTree {
	public:
		CSegTree(const std::vector<int>& source);
		int RMQ(int l, int r);
        int RMQ_mod(int l, int r);
        void modify(int l, int r, int val);
	private:
		std::vector<int> tree;
        std::vector<int> mod_val;
        std::vector<bool> modified;
		int size;
        void applyModify(int pos, int posL, int posR, int l, int r, int val);
        void applyModify_set(int pos, int posL, int posR, int l, int r, int val);
		int getRMQ(int pos, int posL, int posR, int l, int r);
        void sink_mod(int i);
};

int minPow(int s) {
    int size = 1;
    while( size < s)
    	size*=2;
    return size;
}

int left(int p) {
    return 2*p+1;
}

int right(int p) {
    return 2*p+2;
}

CSegTree::CSegTree(const std::vector<int>& source) : size ( minPow(source.size()) ) {
    tree.resize(2 * size);
    mod_val.resize(2 * size);
    modified.resize(2 * size);
    for (unsigned i = size; i >= source.size(); --i)
        tree[size - 1 + i] = INT_MAX;
    for (unsigned i = 0; i < source.size(); ++i)
        tree[size - 1 + i] = source[i];
    for (unsigned i = size - 2; i >= 0; --i)
        tree[i] = std::min( tree[left(i)], tree[right(i)]);
}

int CSegTree::RMQ(int l, int r){
	return getRMQ(0, 0, size - 1, l, r);
}

void CSegTree::modify(int l, int r, int val){
	applyModify(0, 0, size - 1, l, r, val);
}

int CSegTree::getRMQ(int pos, int posL, int posR, int l, int r) {
	if (posL == posR)
		return tree[pos];
	if (l == posL && r == posR)
		return tree[pos];
	const int posM = (posL + posR) / 2;
	int result = INT_MAX;
	if(l <= posM)
		result = getRMQ(2 * pos + 1, posL, posM, l, std::min(r, posM));
	if (r > posM)
		result = std::min(getRMQ(2 * pos + 2, posM + 1, posR,std::max(l, posM + 1), r), result);

	if (!modified[pos])
        return result;
    else
        return tree[pos];
}

void CSegTree::sink_mod(int i) {
    modified[i] = false;
    tree[left(i)] = tree[i];
    modified[left(i)] = true;
    tree[right(i)] = tree[i];
    modified[right(i)] = true;
}

void CSegTree::applyModify(int pos, int posL, int posR, int l, int r, int val){
	if (posL == posR) {
		tree[pos] = val;
        return;
    }
    if (pos <= size && modified[pos])
        sink_mod(pos);
	if (l == posL && r == posR) {
		tree[pos] = val;
        modified[pos] = true;
        return;
    }
    const int posM = (posL + posR) / 2;
    if(l <= posM)
		applyModify(2 * pos + 1, posL, posM, l, std::min(r, posM), val);
	if (r > posM)
		applyModify(2 * pos + 2, posM + 1, posR, std::max(l, posM + 1), r, val);
    if(l <= posM || r > posM)
        tree[pos] = std::min(tree[2 * pos + 1], tree[2 * pos + 2]);
}

int main() {
    int N = 0;
    std::cin >> N;
    std::vector<int> src(N);
    for(int i = 0; i < N; i++) {
        int a = 0, b = 0, c = 0;
        std::cin >> a >> b >> c;
        src[i] = a + b + c;
    }
    CSegTree st(src);

    int K = 0;
    std::cin >> K;
    std::vector<int> result(K);
    for(int i = 0; i < K; i++) {
        int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0;
        std::cin >> a >> b >> c >> d >> e >> f >> g;
        st.modify(a, b, c+d+e);
        result[i] = st.RMQ(f, g);
    }
    for(int i = 0; i < K; i++)
        std::cout<<result[i]<<'\n';
    return 0;
}

