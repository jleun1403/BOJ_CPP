#include <iostream>
#include <algorithm>
#define inf 1500000000
using namespace std;

int tree[400040], treesize, n, m, a[100001];

void init(int node, int left, int right) {
	if (left == right) {
		tree[node] = a[left];
		return;
	}
	init(node * 2, left, (left + right) / 2);
	init(node * 2 + 1, (left + right) / 2 + 1, right);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

void update(int pos, int val) {
	pos += treesize - 1;
	tree[pos] = val;
	while (pos > 1) {
		pos /= 2;
		tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);
	}
}

int query(int node, int nodeleft, int noderight, int left, int right) {
	if (nodeleft > right || left > noderight)
		return inf;
	else if (nodeleft >= left && right >= noderight)
		return tree[node];
	else {
		int q1 = query(node * 2, nodeleft, (nodeleft + noderight) / 2, left, right);
		int q2 = query(node * 2 + 1, (nodeleft + noderight) / 2 + 1, noderight, left, right);
		return min(q1, q2);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 100000; i++) {
		a[i] = inf;
	}
	treesize = 1;
	while (treesize < n) {
		treesize *= 2;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	init(1, 1, treesize);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if (x == 1) {
			update(y, z);
		}
		else {
			printf("%d\n", query(1, 1, treesize, y, z));
		}
	}
}