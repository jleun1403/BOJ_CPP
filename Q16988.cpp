#include<bits/stdc++.h>
using namespace std;

struct Point {
	int x;
	int y;
	bool operator==(const Point &rhs) const {
		return this->x == rhs.x && this->y == rhs.y;
	}
};

int maxi = -1 << 20;
Point position[401];// 검은 돌의 인덱스를 넣었을 때 좌표를 찍어줌
Point blank[400];
int idx = 1;//검은 돌의 인덱스
int bkidx = 0;
int n, m;
int a[20][20];
int setting[20][20];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 ,-1 };
vector<int> v;

void countblack() {
	int total = 0;
	bool ck[20][20] = { false, };
	for (int i = 1; i < idx; i++) {
		if (!ck[position[i].x][position[i].y]) {
			int cnt = 1;
			bool flag = false;
			queue<Point> q;
			q.push(position[i]);
			while (!q.empty()) {
				Point crr = q.front();
				q.pop();
				ck[crr.x][crr.y] = true;
				for (int dir = 0; dir < 4; dir++) {
					int nx = crr.x + dx[dir];
					int ny = crr.y + dy[dir];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && !ck[nx][ny]) {
						if (a[nx][ny] == 2) {
							q.push({ nx, ny });
							ck[nx][ny] = true;
							cnt++;
						}
						if (a[nx][ny] == 0) flag = true;
					}
				}
			}
			if (flag) cnt = 0;
			total += cnt;
		}
	}
	if (total > maxi) maxi = total;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 2) {
				position[idx] = { i,j };//특정 인덱스의 검은돌 실제 위치 저장
				setting[i][j] = idx++;
			}

		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				blank[bkidx++] = { i,j };
			}
		}
	}
	for (int first = 0; first < bkidx - 1; first++) {
		for (int second = first + 1; second < bkidx; second++) {
			a[blank[first].x][blank[first].y] = 1;
			a[blank[second].x][blank[second].y] = 1;

			countblack();

			a[blank[first].x][blank[first].y] = 0;
			a[blank[second].x][blank[second].y] = 0;
		}
    }
	printf("%d", maxi);
}