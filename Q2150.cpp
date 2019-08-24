#include <bits/stdc++.h>

using namespace std;
int vertex_num = 1;
int scc_num = 0;
int discovered[10001];
int scc_group[10001];
vector<vector<int>> v(10001);
vector<vector<int>> ans(10001);
stack<int> st;

bool cmp1(vector<int> &v1, vector<int> &v2) {
	return v1[0] < v2[0];
}


//returns the minimum 
int getSCC(int here) {
	int ret = discovered[here] = vertex_num++;
	st.push(here);
	for (int i = 0 ; i < v[here].size() ; i++) {
		int next = v[here][i];
		if (discovered[next] == -1) {
			ret = min(ret, getSCC(next));
		}
		else if (scc_group[next] == -1) {
			ret = min(ret, discovered[next]);
		}
	}
	if (ret == discovered[here]) {
		while(true) {
			int t = st.top();
			scc_group[t] = scc_num;
			st.pop();
			if (t == here) break;
		}
		scc_num += 1;
	}
	return ret;

}


int main() {
	memset(discovered, -1, sizeof(discovered));
	memset(scc_group, -1, sizeof(scc_group));
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0 ; i < k ; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
	}
	for (int i = 1 ; i <= n ; i++) {
		if (discovered[i] == -1) {
			getSCC(i);
		}
	}

	for (int i = 1 ; i <= n ; i++) {
		ans[scc_group[i]].push_back(i);
		//printf("%d\n", scc_group[i]);
	}
	printf("%d\n", scc_num);
	sort(ans.begin(), ans.begin() + scc_num , cmp1);
	for (int i = 0 ; i < scc_num ; i++) {
		sort(ans[i].begin(), ans[i].end());
	}
	for (int i = 0 ; i < scc_num ; i++) {
		for (int j = 0 ; j < ans[i].size() ; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("-1\n");
	}
	return 0;
}