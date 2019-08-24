#include <bits/stdc++.h>
using namespace std;
char a[14][8];
int ans;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n=12, m =6;
int d[13][7];
int sum, answer;
bool check[13][7];
bool ok = false;
bool seen[13][7];
void bfs(int i, int j){
    queue <pair<int,int>> q;
    queue <pair<int,int>> ans;
    q.push(make_pair(i,j));
    check[i][j] = true;
    ans.push(make_pair(i,j));
    seen[i][j] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx= x + dx[i];
            int ny =y + dy[i];
                if(nx>=0 && nx <n && ny >=0 && ny <m){
                    if(a[nx][ny] == a[x][y] && check[nx][ny] == false){
                        q.push(make_pair(nx,ny));
                        ans.push(make_pair(nx,ny));
                        check[nx][ny] = true;
                        seen[nx][ny] = true;
                    }
                }
            }
        }
    if(ans.size()>=4){
        ok = true;
        while(!ans.empty()){
            int x= ans.front().first;
            int y = ans.front().second;
            //cout << "**" << a[x][y] << ' ';
            a[x][y] = '.';
            d[x][y] = 1;
            ans.pop();
        }
    }
}
int main(){
    for(int i=0; i<12; i++){
        string s;
        cin >> s;
        for(int j=0; j<6; j++){
            a[i][j] = s[j];
        }
    }
    while(true){
        memset(d, 0, sizeof(d));
        memset(seen, false, sizeof(seen));
        ok = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j]!='.' && seen[i][j]== false){
                    memset(check,false,sizeof(check));
                    bfs(i,j);
                }
            }
        }
        if(ok == false) break; // no pop 
        /*cout << "**" << '\n';
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }*/
        for(int j=0; j<m; j++){
            int it = n-1;
            for(int i = n-1; i>=0; i--){
                if(a[i][j] != '.') {
                    if( i == it) it--;
                    else {
                        a[it][j] = a[i][j];
                        a[i][j] = '.';
                        it--;
                    }
                }
                else continue;
            }
        } 
        /*cout << "**" << '\n';
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }*/
        answer +=1;
    }
    cout << answer << '\n';
}
