#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10][10];
int a_copy[10][10];
int dx[4] = {0 ,1 ,0, -1};
int dy[4] = {1, 0 ,-1, 0};
vector <pair<int ,pair<int,int>>> cctv;
queue <pair<int,int>> q;
vector <int> direction;
int answer;
void move(int x, int y, int d){
    int nx =x;
    int ny = y;
    while(nx <n && nx >=0 && ny>=0 && ny <m){
        if(a_copy[nx][ny] ==6) break;
        else a_copy[nx][ny] = a[x][y];
        nx+= dx[d];
        ny+= dy[d];
    }
}
void solve(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            a_copy[i][j] = a[i][j];
        }
    }
    for(int i=0; i<cctv.size(); i++){
        if(cctv[i].first == 1){ //cctv num = 1
            move(cctv[i].second.first, cctv[i].second.second, direction[i]);
        }
        else if(cctv[i].first == 2){
            move(cctv[i].second.first, cctv[i].second.second, direction[i]);
            move(cctv[i].second.first, cctv[i].second.second, (direction[i]+2)%4);
        }
        else if(cctv[i].first == 3){
            move(cctv[i].second.first, cctv[i].second.second, direction[i]);
            move(cctv[i].second.first, cctv[i].second.second, (direction[i]+1)%4);
        }
        else if (cctv[i]. first == 4){
            move(cctv[i].second.first, cctv[i].second.second, direction[i]);
            move(cctv[i].second.first, cctv[i].second.second, (direction[i]+1)%4);
            move(cctv[i].second.first, cctv[i].second.second, (direction[i]+2)%4);
        }
        else if (cctv[i]. first == 5){
            move(cctv[i].second.first, cctv[i].second.second, direction[i]);
            move(cctv[i].second.first, cctv[i].second.second, (direction[i]+1)%4);
            move(cctv[i].second.first, cctv[i].second.second, (direction[i]+2)%4); 
            move(cctv[i].second.first, cctv[i].second.second, (direction[i]+3)%4);           
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a_copy[i][j] == 0) cnt+=1;
        }
    }
    answer= min(answer, cnt);
}
void go(int index){
    if(index == cctv.size()){
        solve();
        return;
    }
    for(int i=0; i<4; i++){
        direction.push_back(i);
        go(index+1);
        direction.pop_back();
    }
}
int main(){
    cin >> n>> m;
    answer = 987654321;
    int sixnum= 0;
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            if(a[i][j] == 6) sixnum+=1;
            if(a[i][j] >=1 && a[i][j] <=5){
                cctv.push_back(make_pair(a[i][j], make_pair(i,j)));
            }
        }
    }
    go(0);

    cout << answer << '\n';
    return 0;

}