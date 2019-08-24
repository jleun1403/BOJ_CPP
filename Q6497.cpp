#include <bits/stdc++.h>
using namespace std;
int n, m;
int parent[200000];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b)
		parent[a] = b;

}
struct Edge
{
	int a;
	int b;
	int dist;
};
vector<Edge> v;

bool cmp(Edge &e1, Edge &e2) {
	return e1.dist < e2.dist;
}

int main() {

	while(true) {
		scanf("%d %d", &m, &n);
		if (n == 0 && m == 0)
			break;
		v.resize(n);
		for (int i = 0 ; i < m ; i++) {
			parent[i] = i;
		}
		int ans = 0;
		int sum = 0;
		for (int i = 0 ; i < n ; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			v[i].a = a;
			v[i].b = b;
			v[i].dist = c;
			sum += c;
		}
		sort(v.begin(), v.end(), cmp);
		for (int i = 0 ; i < n ; i++) {
			int p = v[i].a;
			int q = v[i].b;
			if (Find(p) != Find(q)) {
				Union(p, q);
				ans += v[i].dist;
			}			
		}
		printf("%d\n", sum - ans);
		v.clear();
	}

	return 0;
}