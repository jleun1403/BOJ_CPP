#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > board(101, vector<int> (101, 0));

void make_generation(int x, int y, int dir, int generation) {
	vector<int> ret;
	ret.push_back(dir);
	while(generation--) {
		int cur = ret.size();
		for (int i = cur -1 ; i >= 0 ; i--) {
			int e = ret[i];
			ret.push_back((e + 1) % 4) ;
		}
	}
	/*for (int i = 0 ;i < ret.size() ; i++) {
		printf("%d ", ret[i]);
	} */
	pair<int, int> current = make_pair(x, y);
	board[x][y] = 1;
	for (int i = 0 ; i < ret.size() ; i++) {
		pair<int, int> next;
		if (ret[i] == 0) {
			next.first = current.first + 1;
			next.second = current.second;
		}
		else if (ret[i] == 1) {
			next.first = current.first;
			next.second = current.second - 1;
		}
		else if (ret[i] == 2) {
			next.first = current.first - 1;
			next.second = current.second;
		}
		else {
			next.first = current.first;
			next.second = current.second + 1;
		}
		if (0 <= next.first && next.first <= 100 && 0 <= next.second && next.second <= 100) {
			board[next.first][next.second] = 1;
		}
		//printf("%d %d\n", next.first, next.second);
		current = next;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0 ; i < n ; i++) {
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);
		make_generation(x, y, d, g);
	}
	
	int count = 0;
	for (int i = 1 ; i <= 100 ; i++) {
		for (int j = 1; j <= 100 ; j++) {
			if (board[i-1][j-1] && board[i-1][j] && board[i][j-1] && board[i][j])
				count++;
		}
	}

	printf("%d\n", count);

	return 0;
}