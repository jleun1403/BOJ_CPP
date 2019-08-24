#include <bits/stdc++.h>

using namespace std;

vector<int> tree;
int a[500000];
int n;

int query(int t) {
	int ret = 0;
	while(t > 0) {
		ret += tree[t];
		t -= (t & -t);
	}
	return ret;
}

void update(int t) {
	while(t <= n) {
		tree[t] += 1;
		t += (t & -t);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
		tree.push_back(a[i]);
	}
	sort(tree.begin(), tree.end());
	for (int i = 0 ; i < n ; i++) {
		a[i] = lower_bound(tree.begin(), tree.end(), a[i]) - tree.begin() + 1;
	}
	tree.clear();
	tree.resize(500001);
	long long ans = 0;
	for (int i = 0 ; i < n ; i++) {
		ans += query(n) - query(a[i]);
		update(a[i]);
	}
	printf("%lld\n", ans);
	return 0;
}