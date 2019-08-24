#include <bits/stdc++.h>
#define inf 987654321
using namespace std;

int dp[1001][1001];
int n, w;
pair<int, int> where[1001];
int dist(int, int, int);

int go(int x, int y) {
	int cur = max(x, y);
	int next = max(x, y) + 1;
	if (next == w + 1)
		return 0;
	if (dp[x][y] != -1)
		return dp[x][y];
	int ret = 0;
	ret = min(go(next, y) + dist(x, next, 1), go(x, next) + dist(y, next, 2));
	return dp[x][y] = ret;
}

int dist(int a, int b, int c) {
	pair<int, int> p;
	if (a == 0 && c == 1) {
		p = {1, 1};
	}
	else if (a == 0 && c == 2) {
		p = {n , n};
	}
	else p = where[a];
	auto q = where[b];
	return abs(p.first - q.first) + abs(p.second - q.second);
}

void restore(int x, int y) {
	int next = max(x, y) + 1;
	if (next == w+1)
		return;
	if (go(x, y) == go(next, y) + dist(x, next, 1)) {
		printf("%d\n", 1);
		restore(next, y);
	}
	else {
		printf("%d\n", 2);
		restore(x, next);
	}
}

int main() {
	cin >> n >> w;
	memset(dp, -1, sizeof(dp));
	for (int i = 1 ; i <= w ; i++) {
		cin >> where[i].first >> where[i].second;
	}
	cout << go(0, 0) << '\n';
	restore(0, 0);
	return 0;
}