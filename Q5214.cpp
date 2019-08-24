#include <bits/stdc++.h>
#define inf 987654321
using namespace std;

vector<vector<pair< int, int>>> v(105001);
vector<int> dist(105001, inf);

void dijkstra() {
	//(-dist, vertex)
	priority_queue<pair<int, int>> q;
	dist[1] = 0;
	q.push({0, 1});
	while(!q.empty()) {
		auto p = q.top();
		int cost = p.first * -1;
		int here = p.second;
		q.pop();
		if (dist[here] < cost)
			continue; 
		for (int i = 0 ; i < v[here].size() ; i++) {
			int next = v[here][i].first;
			int weight = v[here][i].second;
			if (dist[next] > dist[here] + weight) {
				dist[next] = dist[here] + weight;
				q.push(make_pair(-dist[next], next));
			}

		}
	}

}

int main() {
	int n, k, m;
	cin >> n >> k >> m;

	for (int i = 0 ;i < m ; i++) {
		int hypertube = n + 1 + i;

		for (int j = 0 ; j < k ; j++) {
			int a;
			cin >> a;
			v[a].push_back({hypertube, 0});
			v[hypertube].push_back({a, 1});
		}
	}
	dijkstra();
	
	printf("%d\n", dist[n] == inf ? -1 : dist[n] + 1);
	return 0;
}