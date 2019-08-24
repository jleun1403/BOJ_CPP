#include <bits/stdc++.h>

using namespace std;

int x[3000];
int y[3000];
int r[3000];

bool is_connected(int a, int b) {
	return sqrt((x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b])) <= r[a] + r[b];
}
vector<vector<int>> v;
bool visited[3000];

void DFS(int x) {
	visited[x] = true;
	for (int i = 0 ; i < v[x].size() ; i++) {
		int next = v[x][i];
		if (!visited[next]) {
			DFS(next);
		}
	}
}

int main() {
	int testcase;
	scanf("%d", &testcase);
	while(testcase--) {

		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		memset(r, 0, sizeof(r));
		memset(visited, false, sizeof(visited));

		int n;
		scanf("%d", &n);
		for (int i = 0 ; i < n ; i++) {
			scanf("%d %d %d", &x[i], &y[i], &r[i]);
		}
		v.resize(n);
		for (int i = 0 ; i < n ; i++) {
			for (int j = i+1 ; j < n ; j++) {
				if (is_connected(i, j)) {
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		int groups = 0;
		for (int i = 0 ; i < n ; i++) {
			if (!visited[i]) {
				groups += 1;
				DFS(i);
			}
		}
		printf("%d\n", groups);
		v.clear();
	}
	return 0;
}