#include <bits/stdc++.h>

using namespace std;
vector<vector<char>> board(10);
//color => 0 == R and 1 == B;
void turn_left(int color, pair<int, int> &p, vector<vector<char>> &v) {
	int left;
	int cx = p.first;
	int cy = p.second;
	for (left = cy-1; left >=0 ; left--) {
		if (board[cx][left] == '#' || board[cx][left] == 'O') {
			return;
		}
	}
}

int main() {


	return 0;
}