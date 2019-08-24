#include <bits/stdc++.h>

using namespace std;

vector<pair<double, double>> stars;
int parent[100];

struct edge {
	int a;
	int b;
	double dist;
};

bool cmp(edge &e1, edge &e2) {
	return e1.dist < e2.dist;
}

double get_dist(int a, int b) {
	return sqrt((stars[a].first - stars[b].first) * (stars[a].first - stars[b].first)
		 + (stars[a].second - stars[b].second)*(stars[a].second - stars[b].second));
}

vector<edge> edges;

int Find(int x) {
	if(x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	parent[x] = y;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i++) {
		double x, y;
		cin >> x>> y;
		stars.push_back(make_pair(x, y));
	}
	for (int i = 0 ; i < n ; i++) {
		for (int j = i+1 ; j < n ; j++) {
			edge e1;
			e1.a = i;
			e1.b = j;
			e1.dist = get_dist(i, j);
			edges.push_back(e1);
		}
	}
	for (int i = 0 ; i < n ; i++) {
		parent[i] = i;
	}
	sort(edges.begin(), edges.end(), cmp);
	double answer = 0.0;
	for (int i = 0 ; i < edges.size() ; i++) {
		int x = edges[i].a;
		int y = edges[i].b;
		x = Find(x);
		y = Find(y);
		if (x == y)
			continue;
		Union(x, y);
		answer += edges[i].dist;
	}

	printf("%lf\n", answer);
	return 0;
}