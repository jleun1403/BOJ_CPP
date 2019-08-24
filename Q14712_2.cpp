#include <bits/stdc++.h>

using namespace std;

int board[25][25];
int n, m;
int answer = 0;

bool possible(int x, int y) {
	if (x == 0) return true;
	if (y == 0) return true;
	if (board[x-1][y-1] && board[x-1][y] && board[x][y-1])
		return false;
	return true;
}

void go(int x, int y) {
	if (x == n) {
		answer++;
		return;
	}
	int nx, ny;
	if (y == m-1) {
		nx = x + 1;
		ny = 0;
	}
	else {
		nx = x;
		ny = y + 1;
	}
	go(nx , ny);
	if (possible(x, y)) {
		board[x][y] = 1;
		go(nx, ny);
		board[x][y] = 0;
	}
	
}

int main() {
	cin >> n >> m;
	go(0 ,0);
	printf("%d\n", answer);
	return 0;	
}