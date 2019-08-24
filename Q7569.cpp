#include <bits/stdc++.h>

using namespace std;
int a[105][105][105];
int mx[6] = { 0,1,0,-1,0,0 };
int my[6] = { 1,0,-1,0,0,0 };
int mz[6] = { 0,0,0,0,1,-1 };
struct Tomato {
	int x;
	int y;
	int z;
	int d;
};
queue<Tomato> q;
int main(){
	int ans = -1;
	int m, n, h;
	int allripe = 1;
	scanf("%d %d %d", &n, &m, &h);
	for (int k = 0; k < h; k++){
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				scanf("%d", &a[i][j][k]);
				if (a[i][j][k] == 1){
					q.push({ i,j,k,0 });
				}
				if (a[i][j][k] == 0){
					allripe = 0;
				}
			}
		}
	}
	if (allripe == 1) {
        printf("0\n"); 
        return 0; 
        }
	while (!q.empty()) {
		int dx = q.front().x;
		int dy = q.front().y;
		int dz = q.front().z;
		int dd = q.front().d;
		q.pop();
		ans = max(dd, ans);
		for (int i = 0; i < 6; i++){
			int xx = dx + mx[i];
			int yy = dy + my[i];
			int zz = dz + mz[i];
			if (xx < 0 || yy < 0 || zz < 0 || xx >= m || yy >= n || zz >= h) continue;
			else{
				if (a[xx][yy][zz] == 0) {
					a[xx][yy][zz] = 1;
					q.push({ xx,yy,zz,dd + 1 });					
				}
			}
		}
	}
	for (int k = 0; k < h; k++){
		for (int i = 0; i < m; i++){
			for (int j = 0; j <n; j++){
				if (a[i][j][k] == 0) {
					printf("-1\n"); 
                    return 0;
				}
			}
		}
	}
	printf("%d\n", ans);
}