#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[101][101];
int direction[101];
int dx[4] = {0, 1, 0, -1}; //오른쪽부터 
int dy[4] = {1, 0, -1, 0};
bool check[101][101];
vector <pair<int,int>> v;
int ans;
int startx, starty;
deque <pair<int,int>> snake;
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        a[x][y] = 2; // apple=2
    }
    cin>> k; //apple num
    for(int i=0; i<k; i++){
        int x;
        char c;
        scanf("%d %c", &x, &c);
        v.push_back(make_pair(x,c));
    }
    v.push_back(make_pair(10001, 'D')); 
    startx =1, starty = 1;
    check[startx][starty] = true;
    snake.push_back(make_pair(startx,starty));
    int start = 0;
    int d= 0; // right
    for(int i=0; i<k+1; i++){
        for(int j = start; j<v[i].first; j++){
            ans +=1;
            startx += dx[d];
            starty += dy[d];
            if(a[startx][starty] == 2) {// if apple
                a[startx][starty] = 0;
                snake.push_back(make_pair(startx,starty));
                check[startx][starty] = true;
            }
            else{
                //game out
                if(check[startx][starty] == true || startx >n || startx <1 || starty >n || starty <1){
                    cout << ans << '\n';
                    return 0;
                }
                // no apple
                check[startx][starty] = true;
                snake.push_back(make_pair(startx, starty));
                check[snake.front().first][snake.front().second] = false;
                snake.pop_front();

            }

        }
        start = v[i].first;
        if(v[i].second == 'D'){
            d+=1;
            if(d==4) d= 0;
        }
        else{
             d-=1;
             if(d==-1) d= 3;
        }
    }
    cout << ans << '\n';
    return 0;
}