#include <bits/stdc++.h>

using namespace std;
int lis[1000002];
bool found[1000002];
int a[1000001];

int main() {
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	for (int i = n ; i > 0 ; i--) {
		int cur = a[i];
		if (found[cur + 1]) {
			found[cur] = true;
			lis[cur] = lis[cur+1] + 1;
		}
		else {
			found[cur] = true;
			lis[cur] = 1;
		}
	}
	int ans = 0;
	for (int i = 1 ; i <= n ; i++) {
		ans = max(ans, lis[i]);
	}
	printf("%d\n", n - ans);
	return 0;
}