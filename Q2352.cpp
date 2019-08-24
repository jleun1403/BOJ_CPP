#include <bits/stdc++.h>
#define MAX 40001
using namespace std;

int maxtree[MAX*4];

void update(int node, int left, int right, int i, int value){
	if (i < left || i > right)
		return;
	maxtree[node] = max(maxtree[node], value);
	if (left != right) {
		update(node*2, left, (left+right)/2 , i, value);
		update(node*2+1, (left+right)/2+1, right, i, value);
	}
}

int query(int node, int nodeleft, int noderight, int left, int right) {
	if (right < nodeleft || left > noderight)
		return -1;
	if (nodeleft >= left && right >= noderight) {
		return maxtree[node];
	}
	int m1 = query(node*2, nodeleft, (nodeleft+noderight)/2 , left, right);
	int m2 = query(node*2+1, (nodeleft+noderight)/2+1, noderight, left, right);
	return max(m1, m2);
}


int main() {
	int n;
	scanf("%d", &n);
	int answer = 0;
	for (int i =1 ; i<= n ; i++) {
		int a;
		scanf("%d", &a);
		int q = query(1, 1, n, 1, a);
		answer = max(answer, q+1);
		update(1, 1, n, a, q+1);
	}
	printf("%d\n", answer);
	return 0;
}