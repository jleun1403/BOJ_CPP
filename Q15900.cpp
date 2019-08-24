#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> v(500001);
bool isLeaf[500001];
bool visited[500001];

void DFS(int x) {
	visited[x] = true;
	bool isleaf = true;
	for (int i= 0 ; i < v[x].size() ; i++) {
		int next = v[x][i];
		if (!visited[next]) {
			isleaf = false;
			DFS(next);
		}
	}
	if (isleaf) {
		isLeaf[x] = true;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0 ; i < n-1 ; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	//DFS(1);
	int answer = 0;
	for (int i = 2 ; i <= n ; i++) {
		if (v[i].size() == 1)
			answer++;
	}
	if (answer % 2 == 0) {
		printf("No\n");
	}
	else printf("Yes\n");

	return 0;
}