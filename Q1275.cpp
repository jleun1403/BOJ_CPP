#include <bits/stdc++.h>

using namespace std;

long long tree[100001];
long long current[100001];
int n, q;

void update(int x, int value) {
	long long diff = (long long)value - current[x];
	while(x <= n) {
		tree[x] += diff;
		x += (x & -x);
	}
}

long long query(int x) {
	long long ret = 0;
	while(x > 0) {
		ret += tree[x];
		x -= (x & -x);
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1 ; i <= n ; i++) {
		int a;
		scanf("%d", &a);
		update(i, a);
		current[i] = a;
	}
	for (int i = 0 ; i < q ; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a > b)
			swap(a, b);
		printf("%lld\n", query(b) - query(a-1));
		update(c, d);
		current[c] = d;

	}
	return 0;
}