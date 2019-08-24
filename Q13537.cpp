#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v(400041);
void update(int node, int left, int right, int pos, int value) {
	if (pos < left || pos > right)
		return;
	v[node].push_back(value);
	if (left == right)
		return;
	update(node * 2, left, (left + right) / 2, pos, value);
	update(node * 2 + 1, (left + right)/2 + 1, right, pos, value);
}

int query(int node, int left, int right, int nodeleft, int noderight, int k) {
	if (nodeleft > right || left > noderight)
		return 0;
	if (right >= noderight && nodeleft >= left) {
		return v[node].end() - upper_bound(v[node].begin(), v[node].end(), k);
	}
	else {
		int q1 = query(node * 2, left, right, nodeleft, (nodeleft + noderight) / 2, k);
		int q2 = query(node * 2 + 1, left, right, (nodeleft + noderight) / 2 + 1, noderight, k);
		return q1 + q2;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		update(1, 1, n, i, x);
	}
	for (int i = 1; i <= 400040; i++) {
		sort(v[i].begin(), v[i].end());
	}
	int m;
	scanf("%d", &m);
	int last_ans = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a = a ^ last_ans;
		b = b ^ last_ans;
		c = c ^ last_ans;
		last_ans = query(1, a, b, 1, n, c);
		printf("%d\n", last_ans);
	}
}