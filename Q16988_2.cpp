#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <pair<int,int>> v;
int a[21][21];
int a_copy[21][21];
int d[21][21];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int answer;
int dcount;
bool c[21][21];
bool check(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(d[i][j] == 1){
                int x= i;
                int y = j;
                for(int k=0; k<4; k++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx == -1 || nx ==n || ny ==-1 || ny ==m) continue;
                    else if(a_copy[nx][ny] != 1 && a_copy[nx][ny]!=2) return false;
                }
            }
        }
    }
    return true;
}
void dfs(int x, int y, int cnt){
    d[x][y] =cnt;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny =y + dy[i];
        if(nx>=0 && nx <n && ny >=0 && ny <m){
            if(d[nx][ny] == 0 && a[nx][ny] == 2){
                dfs(nx,ny, cnt);
            }
        }
    }
}
int main(){
    cin >> n>> m;
    for(int i=0 ; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] ==0) v.push_back(make_pair(i,j));
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cnt+=1;
            if(a[i][j] ==2 && d[i][j] == 0) dfs(i,j, cnt);
        }
    }

    for(int i=0; i<v.size()-1; i++){
        for(int j=i+1; j<v.size(); j++){
            int ans = 0;
            for(int p=0; p<n; p++){
                for(int q=0; q<m; q++){
                    a_copy[i][j] = a[i][j];
                }
            }
            a_copy[v[i].first][v[i].second] = 1;
            a_copy[v[j].first][v[j].second] = 1;
           for(int k=1; k<=cnt; k++){
               for(int p=0; p<n; p++){
                   for(int q=0; q<m; q++){
                       
                   }
               }
           }
            
            answer = max(answer, ans);
        }
    }
    cout << answer << '\n';
    return 0;
}