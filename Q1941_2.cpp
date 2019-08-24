#include <bits/stdc++.h>
using namespace std;
char arr[6][6];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool check[5][5];
int go[5][5];
int d[5][5];
int ans = 0;
int cnt;
void dfs(int x, int y, int cnt){
    d[x][y] = cnt;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<5 && ny >=0 && ny <5){
            if(d[nx][ny] == 0 && go[nx][ny] ==1){
                cnt+=1;
                dfs(nx,ny, cnt);
            }
        }
    }

}
bool countS(){
    int counts=0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(go[i][j] == 1 && arr[i][j] =='S'){
                counts+=1;
            }
        }
    }
    if(counts>=4) return true;
    else return false;
}
int main(){
    for(int i=0; i<5; i++){
        string s;
        cin >> s;
        for(int j=0; j<5; j++){
            arr[i][j] = s[j];
        }
    }
    vector<int> v;
    for(int i=0; i<7; i++){
        v.push_back(1);
    }
    for(int i=0; i<18; i++){
        v.push_back(0);
    }
    sort(v.begin(),v.end());
    do{
        for(int i=0; i<25; i++){
            if(v[i]==1){
                go[i/5][i%5] =1;
            }
        }
        cnt = 0;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(go[i][j] ==1 && d[i][j] == 0){
                    cnt += 1;
                    dfs(i,j,cnt);
                }
            }
        }
        if(cnt ==1 && countS()== true) ans +=1;
        //memset(check,false, sizeof(check));
        memset(go, 0, sizeof(go));
        memset(d, 0, sizeof(d));
    }while(next_permutation(v.begin(),v.end()));
  cout << ans << '\n';
  return 0;
}