#include <bits/stdc++.h>
using namespace std;
int dp[5000][5000];
vector<int> v;
int n;

bool isPalindrome(int x, int y) {
	if (x >= y)
		return true;
	if (v[x] != v[y])
		return false;
	return isPalindrome(x+1, y-1);
}

int solve(int x, int y) {
	if (x >= y)
		return 0;
	if (isPalindrome(x, y))
		return 0;
	if (dp[x][y] != -1)
		return dp[x][y];
	if (v[x] == v[y]) {
		return dp[x][y] = solve(x+1, y-1);
	}
	else
		return dp[x][y] = min(solve(x+1, y), solve(x, y-1)) + 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 0 ; i < n ; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", solve(0, n-1));
	return 0;
}