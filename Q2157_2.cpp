#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int path[301][301];
int dp[301][301];
int n, m, k;

int go(int cur, int cities) {
	if (cur == n) {
		if (cities <= m)
			return 0;
		else return -inf;
	}
	if (cities == m) return -inf;
	int &ret = dp[cur][cities];
	if (ret != -1)
		return ret;
	ret = -inf;
	for (int next = cur +1 ; next <= n ; next++) {
		if (path[cur][next]) {
			ret = max(ret, path[cur][next] + go(next, cities+1));
		}
	}
	return ret;
}

int main() {
	cin >> n >> m >> k;
	memset(dp, -1, sizeof(dp));
	for (int i = 0 ; i < k ; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b)
			continue;
		path[a][b] = max(path[a][b], c);
	}
	cout << go(1, 1) << '\n';
	return 0;
}