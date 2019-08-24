#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[103][103];
int dx[4] = {0, 1 , 0, -1};
int dy[4] = {1, 0 , -1, 0};
bool check[103][103];
int answer;
vector<pair<int,char>> v;
deque <pair<int,int>> dq;
int main(){
    scanf("%d %d", &n, &k);
    for(int i=0; i<k; i++){
        int x, y;
        scanf("%d %d" , &x, &y);
        a[x][y] = 3;
    }
    int l;
    cin >> l;
    for(int i=0; i<l; i++){
        int num;
        char d;
        scanf("%d %c", &num, &d);
        v.push_back(make_pair(num,d));
    }
    v.push_back(make_pair(1010, 'D'));
    check[1][1] = true;
    dq.push_back(make_pair(1,1));

    int start = 0;
    int dir = 0;
    bool ok = false;
    int x =1, y=1;
    for(int t =0; t<v.size(); t++){
        for(int i= start; i<v[t].first; i++){
            x += dx[dir];
            y += dy[dir];
            if(check[x][y] == true || x == n+1 || y==n+1 || x == 0 || y ==0 ){
                ok = true;
                answer+=1;
                break;
            }
            check[x][y] = true;
            if(a[x][y] == 3){
                a[x][y] = 0;
                dq.push_back(make_pair(x,y));
                
            }
            else{
                dq.push_back(make_pair(x,y));
                check[dq.front().first][dq.front().second] = false;
                dq.pop_front();
            }
            answer+=1;
        }
        if(ok == true) break;
        start = v[t].first;
        if(v[t].second == 'L'){
            dir-=1;
            if(dir == -1) dir= 3;
        }
        else if(v[t].second == 'D'){
            dir+=1;
            if(dir == 4) dir = 0;
        }
        //change dir

    }
    cout << answer << '\n';
    return 0;
}