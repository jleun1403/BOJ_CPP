#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10][10];
int a_copy[10][10];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ans;
bool check[10][10];
void dfs(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx <n && ny >=0 && ny <m && a_copy[nx][ny] ==0){
            a_copy[nx][ny] = 2;
            dfs(nx,ny);
        }
    }
    //check[x][y] = false;
}
int countzero(){
    int ret= 0;
    for(int i=0; i<n; i++){
        for(int j =0; j<m; j++){
            if(a_copy[i][j] ==0) ret+=1;
        }
    }
    return ret;
}
int main(){
    cin >> n>> m;
    vector<pair<int,int>> v;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            a_copy[i][j] = a[i][j];
            if(a[i][j] == 0){
                v.push_back(make_pair(i,j));
            }
        }
    }
    for(int i=0; i<v.size()-2; i++){
        for(int j=i+1; j<v.size()-1; j++){
            for(int k=j+1; k<v.size(); k++){

                for(int p=0; p<n; p++){
                    for(int q=0; q<m; q++){
                        a_copy[p][q] = a[p][q];
                    }
                }
                a_copy[v[i].first][v[i].second] = 1;
                a_copy[v[j].first][v[j].second] = 1;
                a_copy[v[k].first][v[k].second] = 1;
                for(int p=0; p<n; p++){
                    for(int q=0; q<m; q++){
                        if(a_copy[p][q] == 2){
                            dfs(p, q);
                        }
                    }
                }
                ans = max(countzero(), ans);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}