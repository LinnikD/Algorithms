//============================================================================
// Name        : Семенар.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <cmath>
using namespace std;

void Compute_ST(int *A, int N, int **M ){
    int i, j;
    for(i = 0; i < N; i++)
        M[i][0] = i;
    for(j = 1; 1 << j <= N ; j++){
        for(i = 0; i + (1 << (j - 1)) < N; i++){
            if(A[M[i][j - 1]] <= A[M[i + (1 << (j - 1))][j - 1]])
                M[i][j]=M[i][j - 1];
            else
                M[i][j]=M[i + (1 << (j - 1))][j - 1];
        }
    }
}

int RMQ(int *A, int s, int e, int ** M){
    int k = e - s;
    if(s == e)
    	return s;
    k=31 - __builtin_clz(k + 1);
    if(A[M[s][k]] <= A[M[e - (1 << k) + 1][k]])
        return M[s][k];
    return M[e - (1 << k) + 1][k];
}

int main(){

    int n, m, **M;
    cin >> n >> m;
    int logn = ceil(log2(n));
    int l, r;
    M = new int* [n];
    for(int i = 0; i < n; i++) {
        M[i] = new int[logn + 1];
    }
    int * A = new int[n];
    for(int i = 0; i < n; i++)
    	cin >> A[i];
    Compute_ST(A, n, M);
    int ans;
    for(int j = 0;j < m;j ++) {
    	cin >> l >> r;
    	l--, r--;
    	int i = RMQ(A, l, r, M);
    	if(i == l)
    		ans = A[RMQ(A, l + 1, r, M)];
    	else
    		if(i == r)
    			ans = A[RMQ(A, l, r - 1, M)];
    		else
    			ans = min(A[RMQ(A, l, i - 1, M)], A[RMQ(A, i + 1, r, M)]);
    cout << ans << '\n';
    }

    delete[] A;
    for(int i = 0; i < n; i++) {
        delete[] M[i];
    }
    delete[] M;

    return 0;
}

