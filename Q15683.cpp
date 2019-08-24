#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10][10];
int a_copy[10][10];
int dir[10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<pair<int, pair<int,int>>> cctv;
int answer = 987654321;
void move(int x, int y, int d){
    int temp = a_copy[x][y];
    while(true){
        x+=dx[d];
        y+=dy[d];
        if(x >=0 && x <n && y >=0 && y <m && a_copy[x][y] !=6){
            a_copy[x][y] = temp;
        }
        else break;
    }
}
void solve(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            a_copy[i][j] = a[i][j];
        }
    }
    for(int i=0; i<cctv.size(); i++){
        int num = cctv[i].first;
        int d = dir[i];
        if(num == 1){
            move(cctv[i].second.first, cctv[i].second.second, d);
        }
        else if(num ==2){
            move(cctv[i].second.first, cctv[i].second.second, d);
            move(cctv[i].second.first, cctv[i].second.second, (d+2)%4);
        }
        else if(num == 3){
            move(cctv[i].second.first, cctv[i].second.second, d);
            move(cctv[i].second.first, cctv[i].second.second, (d+3)%4);
        }
        else if(num == 4){
            move(cctv[i].second.first, cctv[i].second.second, d);
            move(cctv[i].second.first, cctv[i].second.second, (d+2)%4);
            move(cctv[i].second.first, cctv[i].second.second, (d+3)%4);
        }
        else if (num ==5){
            move(cctv[i].second.first, cctv[i].second.second, d);
            move(cctv[i].second.first, cctv[i].second.second, (d+1)%4);
            move(cctv[i].second.first, cctv[i].second.second, (d+2)%4);
            move(cctv[i].second.first, cctv[i].second.second, (d+3)%4);
        }
    }
    int sum =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a_copy[i][j] == 0) sum+=1;
        }
    }
    answer = min(answer, sum);
}
void go(int cnt){
    if(cnt == cctv.size()){
        solve();
        return ;
    }
    for(int i=0; i<4; i++){
        dir[cnt] = i;
        go(cnt+1);
    }
}
int main(){
    cin >> n>> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] >=1 && a[i][j] <=5){
                cctv.push_back(make_pair(a[i][j], make_pair(i,j)));
            }
        }
    }
    go(0);
    cout << answer << '\n';
    return 0;
}
