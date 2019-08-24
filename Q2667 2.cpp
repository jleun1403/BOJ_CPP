#include <bits/stdc++.h>
using namespace std;
int n;
int a[26][26];
bool check[26][26];
int d[26][26];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int num[25*25+1];
void dfs(int x, int y, int cnt){
    //num+=1;
    d[x][y] = cnt;
    for(int i=0; i<4 ; i++){
        int nx = x+dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx <n && ny>=0 && ny <n){
            if(d[nx][ny] == 0 && a[nx][ny] == 1){
                dfs(nx,ny,cnt);
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    int cnt= 0;
    vector <int> v;
    for(int i=0; i<n; i++){
        for(int j=0;j<n; j++){
            if(a[i][j] ==1 && d[i][j] ==0){
                cnt+=1;
                dfs(i,j, cnt);
            }
        }
    }
    cout << cnt << '\n';

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(d[i][j]!=0){
                num[d[i][j]]+=1;
            }
        }
    }
    sort(num+1, num+cnt+1);
    for(int i=1; i<=cnt; i++){
        cout << num[i] << '\n';
    }
    return 0;
}