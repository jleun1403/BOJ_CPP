#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

vector<vector<int>> v(100001);
vector<vector<int>> children(100001);
int dp[100001][30];
bool visited[100001];
int n;

void DFS(int x) {
	visited[x] = true;
	for (int i = 0 ; i < v[x].size() ; i++) {
		int next = v[x][i];
		if (!visited[next]) {
			visited[next] = true;
			children[x].push_back(next);
			DFS(next);
		}
	}
}

int go(int root, int color) {
	int &ret = dp[root][color];
	if (ret != -1)
		return ret;

	ret = inf;
	for (int i = 1 ; i < 30 ; i++) {
		if (color == i)
			continue;
		int temp = i;
		for (int j = 0 ; j < children[root].size() ; j++) {
			int next = children[root][j];
			temp += go(next, i);
		}
		ret = min(ret, temp);
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0, a, b; i < n-1 ; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	DFS(1);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(1, 0));
	return 0;
}