#include <bits/stdc++.h>
using namespace std;

int tree[400401];
int n;
vector<pair<int, int>> v(100001);

void update(int index, int value, int node, int left, int right) {
	if (index < left || index > right)
		return;
	tree[node] += value;
	if (left != right) {
		update(index, value, node*2, left, (left+right)/2);
		update(index, value, node*2+1, (left+right)/2+1, right);
	}
}

int sum(int node, int nodeleft, int noderight, int left, int right) {
	if (nodeleft > right || left > noderight)
		return 0;
	if (nodeleft >= left && right >= noderight)
		return tree[node];
	else {
		int m1 = sum(node*2, nodeleft, (nodeleft+noderight)/2, left, right);
		int m2 = sum(node*2+1, (nodeleft+noderight)/2+1, noderight, left, right);
		return m1 + m2;
	}
}

int main() {
	cin >> n;
	for (int i = 0 ; i < n ; i++) {
		int midterm;
		cin >> midterm;
		update(midterm, 1, 1, 1, n);
		int q1 = sum(1, 1, n, midterm+1, n);
		if (midterm == n)
			q1 = 0;
		int q2 = sum(1, 1, n, 1, midterm - 1);
		int q3 = midterm - 1 - q2;
		if (midterm == 1) {
			q3 = 0;
		}

		v[midterm].first = q1;
		v[midterm].second = q3;
	}
	for (int i = 1 ;i <= n ; i++) {
		printf("%d\n", v[i].second - v[i].first);
	}


	return 0;
}