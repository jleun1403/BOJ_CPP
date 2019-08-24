#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
bool visited[2000][2000];
int dist[2000][2000];



void BFS() {
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	while(!q.empty()){
		auto p = q.front();
		q.pop();
		int emoticon = p.first;
		int clipboard = p.second;
		int cur = dist[emoticon][clipboard];

		// Copy
		if (!visited[emoticon][emoticon]){
			q.push(make_pair(emoticon, emoticon));
			dist[emoticon][emoticon] = cur + 1;
			visited[emoticon][emoticon] = true;
		}
		// Paste
		if (clipboard != 0 && emoticon + clipboard < 2000 && !visited[emoticon+clipboard][clipboard]) {
			q.push(make_pair(emoticon + clipboard, clipboard));
			dist[emoticon + clipboard][clipboard] = cur + 1;
			visited[emoticon+clipboard][clipboard] = true;
		}

		// Remove
		if (emoticon > 0 && !visited[emoticon-1][clipboard]) {
			q.push(make_pair(emoticon -1, clipboard));
			dist[emoticon-1][clipboard] = cur + 1;
			visited[emoticon-1][clipboard] = true;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	BFS();
	int ans = inf;
	for (int i = 0 ; i < 2000 ; i++) {
		if (dist[n][i] > 0)
			ans = min(ans, dist[n][i]);
	}

	printf("%d\n", ans);
	return 0;
}