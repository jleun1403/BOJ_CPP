#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int>> v;
int visited[10001];
int isVertexCut[10001];
int counter = 0;


int DFS(int here, bool isRoot) {
	visited[here] = counter++;
	int children = 0;
	int ret = visited[here];
	for (int i = 0 ; i < v[here].size() ; i++) {
		int next = v[here][i];
		if (visited[next] == -1) {
			children++;
			int subtree = DFS(next, false);
			if (!isRoot && subtree >= visited[here]) {
				isVertexCut[here] = true;
			}
			ret = min(ret, subtree);
		}
		else {
			ret = min(ret, visited[next]);
		}
	}
	if (isRoot) {
		if (children >= 2) {
			isVertexCut[here] = true;
		}
	}
	return ret;
}

int main() {
	cin >> n >> m;
	v.resize(n+1);
	memset(visited, -1, sizeof(visited));
	for (int i = 0 ; i < m ; i++) {
		int a, b;
		cin >> a>> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i =1 ; i<= n ; i++) {
		if (visited[i] == -1) {
			DFS(i, true);
		}
	}
	int ans = 0;
	for (int i =1 ; i<= n ; i++) {
		if (isVertexCut[i]) {
			ans++;
		}
	}
	cout << ans << '\n';
	for (int i =1 ; i<= n ; i++) {
		if (isVertexCut[i]) {
			cout << i << ' ' ;
		}
	}
	return 0;
}