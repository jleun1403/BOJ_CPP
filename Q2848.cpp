#include <bits/stdc++.h>
using namespace std;
bool exists[26];
int indegree[26];
int outdegree[26];
int indegree2[26];
vector<vector<int>> v(26);
vector<int> visited(26, -1);
vector<bool> finished(26, false);

int cnt = 1;
bool has_cycle = false;

void DFS(int x) {
	visited[x] = cnt++;
	for (int i = 0 ; i < v[x].size() ; i++) {
		int next = v[x][i];
		if (visited[next] == -1) {
			DFS(next);
		}
		else if (visited[x] > visited[next] && !finished[next]){
			has_cycle = true;
		}
	}
	finished[x] = true;
}

int main() {
	int n;
	cin >> n;
	memset(exists, false, sizeof(exists));
	vector<string> t;
	for (int i = 0 ; i < n ; i++) {
		string s;
		cin >> s;
		t.push_back(s);
		for (int k = 0 ; k < s.length() ; k++) {
			exists[s[k] - 'a'] = true;
		}
	}
	if (n == 1 && t[0].length() == 1) {
		printf("%c", t[0][0]);
		return 0;
	}
	if (n == 1) {
		int existnum = 0;
		for (int i = 0 ; i <26 ; i++) {
			if (exists[i])
				existnum++;
		}
		if (existnum == 1) {
			printf("%c", t[0][0]);
			return 0;
		}
	}
	for (int i = 1 ;i  < n ; i++) {
		string s1 = t[i-1];
		string s2 = t[i];
		if (s1 == s2)
			continue;
		if (s1.length() < s2.length() && s2.substr(0, s1.length()) == s1) {
			continue;
		}
		if (s1.length() > s2.length() && s1.substr(0, s2.length()) == s2) {
			printf("!");
			return 0;
		}
		for (int j = 0 ; j < min(s1.length(), s2.length()) ; j++) {
			if (s1[j] != s2[j]) {
				int from = s1[j] - 'a';
				int to = s2[j] - 'a';
				v[from].push_back(to);
				indegree[to] += 1;
				indegree2[to] += 1;
				outdegree[from] += 1;
				break;
			}
		}
	}
	for (int i = 0 ; i < 26 ; i++) {
		if (exists[i]) {
			if (visited[i] == -1) {
				DFS(i);
			}
			if (has_cycle) {
				printf("!");
				return 0;
			}
		}
	}


	queue<int> q;
	
	vector<char> ans;
	visited.clear();
	visited.resize(26, 0);

	for (int i = 0 ; i < 26 ; i++) {
		if (exists[i] && indegree[i] == 0) {
			q.push(i);
			visited[i] = 1;
			ans.push_back(i + 'a');
		}
	}
	while(!q.empty()) {
		if (q.size() > 1) {
			printf("?");
			return 0;
		}
		int cur = q.front();
		q.pop();
		
		for (int i = 0 ; i < v[cur].size() ; i++) {
			int next = v[cur][i];
			indegree[next] -= 1;
			if (indegree[next] == 0 && visited[next] == 0) {
				visited[next] = 1;
				ans.push_back(next + 'a');
				q.push(next);
			}
		}
	}

	
	for (int i = 0 ; i < ans.size() ; i++) {
		printf("%c", ans[i]);
	}
	
	return 0;
}