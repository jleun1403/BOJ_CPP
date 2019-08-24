#include <bits/stdc++.h>
#define inf 2000000020

using namespace std;
int n, m;
vector<int> a;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0 ; i < n ; i++) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	int ans = inf;
	for (int i = 0 ; i < n ;i++) {
		int target = a[i] + m;
		auto p = lower_bound(a.begin(), a.end(), target);
		if (p == a.end())
			continue;
		else ans = min(ans, (*p) - a[i]);
	}
	printf("%d\n", ans);
	return 0;
}