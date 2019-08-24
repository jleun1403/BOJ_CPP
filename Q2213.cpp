#include <bits/stdc++.h>

using namespace std;
int n;
int a[10001];
int dp[10001][2];
vector<vector<int>> v(10001);
bool visited[10001];
vector<vector<int>> children(10001);
vector<int> isMaxCover;

void DFS(int here){
	visited[here] = true;
	for (int i = 0 ; i < v[here].size() ; i++) {
		int next = v[here][i];
		if (!visited[next]) {
			children[here].push_back(next);
			DFS(next);
		}
	}
}

// chosen : the parent of the node is chosen
int Max_Independent_Cover(int root, int chosen) {
	int &ret = dp[root][chosen];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0 ; i < children[root].size() ; i++) {
		int next = children[root][i];
		ret += Max_Independent_Cover(next, 0);
	}
	if (chosen == 1)
		return ret;
	int cnt = a[root];
	for (int i = 0 ; i <children[root].size() ; i++) {
		int next = children[root][i];
		cnt += Max_Independent_Cover(next, 1);
	}
	ret = max(cnt, ret);
	
	return ret;
}

void get_answer(int root, int chosen) {
	if (chosen) {
		for (int i = 0 ; i < children[root].size(); i++) {
			get_answer(children[root][i], 0);
		}
	}
	else {
		int sum = 0;
		for (int i = 0 ; i < children[root].size() ; i++) {
			sum += Max_Independent_Cover(children[root][i], 1);
		}
		if (sum + a[root] == Max_Independent_Cover(root, 0)) {
			isMaxCover.push_back(root);
			for (int i : children[root])
				get_answer(i, 1);
		}
		else {
			for (int i : children[root])
				get_answer(i, 0);
		}
	}
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 1 ;i <= n ; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0 ; i < n - 1 ; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		v[p].push_back(q);
		v[q].push_back(p);
	}
	DFS(1);
	printf("%d\n", Max_Independent_Cover(1, 0));
	get_answer(1, 0);
	sort(isMaxCover.begin(), isMaxCover.end());
	for (int i = 0 ; i< isMaxCover.size() ; i++) {
		printf("%d ", isMaxCover[i]);
	}
	return 0;
}