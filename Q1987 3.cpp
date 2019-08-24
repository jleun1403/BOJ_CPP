#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[21][21];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool check[21][21];
bool alphabet[27];
int ans;
void dfs(int x, int y,int cnt){

    alphabet[a[x][y]-'A'] = true;
    for(int i=0; i<4; i++){
        int nx = x +dx[i];
        int ny =  y + dy[i];
        if(nx>=0 && nx <n && ny >=0 && ny <m){
            if(alphabet[a[nx][ny]-'A'] == false){
                dfs(nx,ny,cnt+1);
            }
        }

    }
    alphabet[a[x][y]-'A'] = false;
    ans = max(ans, cnt);
}
int main(){
    cin >> n>> m;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            a[i][j] = s[j];
        }
    }
    dfs(0,0,1);
    cout << ans << '\n';
    return 0;
}