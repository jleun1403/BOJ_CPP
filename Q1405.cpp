#include <bits/stdc++.h>

using namespace std;
int n;
int east, west, south, north;
bool visited[50][50];
double dp[50][50];

double go(int x, int y, int steps) {
	if (visited[x][y]) return 0;
	if (steps == n) return 1;
	visited[x][y] = true;
	double ret = 0.0;
	ret += go(x -1 , y, steps + 1) * north / 100.0;
	ret += go(x + 1, y, steps + 1) * south / 100.0;
	ret += go(x, y+1, steps + 1) * east / 100.0;
	ret += go(x, y-1, steps + 1) * west / 100.0;
	visited[x][y] = false;
	return ret;

}

int main() {
	scanf("%d", &n);
	scanf("%d %d %d %d", &east, &west, &south, &north);
	printf("%.9lf", go(25, 25, 0));
	return 0;
}