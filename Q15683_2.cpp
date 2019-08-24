#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[4] = {0 ,1 ,0, -1};
int dy[4] = {1, 0 ,-1, 0};

vector<vector<int>> a(10, vector<int> (10));
vector<vector<int>> b(10);
vector<pair<int,pair<int,int>>> cctv;
vector<int> dir;
int ans = 987654321;

void printvector(vector<int> &v) {
    for (int i = 0 ; i < v.size() ; i++) {
        printf("%d " , v[i]);
    }
    printf("\n");
}

void move(int i, int j, int num){
    int x = i;
    int y = j;
    while(x>=0 && x<n && y>=0 && y<m){
        if(a[x][y] == 6) break;
        b[x][y] = a[i][j];
        x+=dx[num];
        y+=dy[num];
    }
}
void go(int index, vector<int> &dir){

    if(cctv.size() == index){
        //printvector(dir);
        b.clear();
        b.resize(n, vector<int> (m));
        for(int i=0; i<cctv.size(); i++){
            int number, x, y;
            number =cctv[i].first;
            x = cctv[i].second.first;
            y = cctv[i].second.second;
            if(number == 1){
                move(x,y,dir[i]);
            }
            else if(number == 2){
                move(x,y,dir[i]);
                move(x,y,(dir[i]+2)%4);
            }
            else if(number == 3){
                move(x, y, dir[i]);
                move(x,y,(dir[i]+1)%4);
            }
            else if(number == 4){
                move(x,y,dir[i]);
                move(x,y,(dir[i]+1) %4);
                move(x,y,(dir[i]+2) %4);
            }
            else if(number == 5){
                move(x,y,dir[i]);
                move(x,y,(dir[i]+1)%4);
                move(x,y,(dir[i]+2)%4);
                move(x,y,(dir[i]+3)%4);
            }

        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(b[i][j] == 0){
                    cnt+=1;
                }
            }
        }
        ans = min(ans, cnt);
        return;
    }
    for(int i=0; i<4; i++){
        dir[index] = i;
        go(index + 1, dir);
    }
}
int main(){
    cin >> n>> m;
    int num6 = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            if(a[i][j] == 6) num6 +=1;
            if(a[i][j]>=1 && a[i][j] <=5){
                cctv.push_back(make_pair(a[i][j], make_pair(i, j)));
                dir.push_back(0);
            }
        }
    }
    go(0, dir);

    cout << ans-num6 << '\n';
    return 0;

}