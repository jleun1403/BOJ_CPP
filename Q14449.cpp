#include <bits/stdc++.h>

using namespace std;

int board[20][20];

class Dice{
public:
	int up, down, front, back, right, left;
	Dice() {
		up = down = front = back = right = left = 0;
	}
	void roll_up() {
		int temp = down;
		down = back;
		back = up;
		up = front;
		front = temp;
	}
	void roll_down() {
		int temp = down;
		down = front;
		front = up;
		up = back;
		back = temp;
	}
	void roll_right() {
		int temp = down;
		down = left;
		left = up;
		up = right;
		right = temp;
	}
	void roll_left() {
		int temp = down;
		down = right;
		right = up;
		up = left;
		left = temp;
	}
};

int main() {
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < m ; j++) {
			cin >> board[i][j];
		}
	}
	int posx = x;
	int posy = y;
	Dice dice = Dice();

	for (int i = 0 ; i < k ; i++) {
		int dir;
		cin >> dir;
		if (dir == 1) {
			if (posy == m-1)
				continue;
			posy++;
			dice.roll_right();
		}
		else if (dir == 2) {
			if (posy == 0)
				continue;
			posy--;
			dice.roll_left();
		}
		else if (dir == 3) {
			if (posx == 0)
				continue;
			posx--;
			dice.roll_up();
		}
		else  {
			if (posx == n-1)
				continue;
			posx++;
			dice.roll_down();
		}

		if (board[posx][posy] == 0) {
			board[posx][posy] = dice.down;
		}
		else {
			dice.down = board[posx][posy];
			board[posx][posy] = 0;
		}
		printf("%d\n", dice.up);
	}

	return 0;
}