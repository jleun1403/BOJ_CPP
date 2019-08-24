#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[52][52];
int dx[4] = { -1, 1, 0 ,0};
int dy[4] = { 0, 0 ,- 1, 1};
int d[52][52];
bool check[52][52];
int answer = 0;
int bfs(int i, int j){
    int ans = 0;
    d[i][j] = 1;
    queue<pair<int,int>>q;
    q.push(make_pair(i,j));
    while(!q.empty()){
        int x= q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx <n && ny >=0 && ny <m){
                if(d[nx][ny] == 0 && a[nx][ny] == 'L'){
                    d[nx][ny] = d[x][y] +1;
                    q.push(make_pair(nx,ny));
                    ans = max(ans, d[nx][ny]);
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans = max(ans, d[i][j]);
        }
    }
    return ans;
}
int main(){
    cin >> n>> m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                scanf(" %c", &a[i][j]);
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] =='L'){
                    int sum =0;
                    memset(d, 0, sizeof(d));
                    sum = bfs(i,j);
                    //cout << sum << '\n';
                    answer = max(answer, sum);
                }
            }
        }

        cout << answer-1 << '\n';
        return 0;
}