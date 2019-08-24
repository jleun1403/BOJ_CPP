#include <bits/stdc++.h>

using namespace std;
bool cannot[201][201];
int n, m;
int ans = 0;

void choose(int first, int second, int third) {
	if (third != -1) {
		ans += 1;
		return;
	}
	else if (second != -1) {
		for (int next = second + 1 ; next <= n ; next++) {
			if (!cannot[first][next] && !cannot[second][next]) {
				choose(first, second, next);
			}
		}
	}
	else if (first != -1) {
		for (int next = first + 1 ; next <= n ; next++) {
			if (!cannot[first][next]) {
				choose(first, next, -1);
			}
		}
	}
	else {
		for (int next = 1 ; next <= n ; next++) {
			choose(next, -1, -1);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0 ; i< m ; i++) {
		int a, b;
		cin >> a>> b;
		cannot[a][b] = true;
		cannot[b][a] = true;
	}
	choose(-1, -1, -1);
	cout << ans << '\n';
	return 0;
}