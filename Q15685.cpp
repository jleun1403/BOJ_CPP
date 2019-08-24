#include <bits/stdc++.h>
using namespace std;
int a[101][101];
int dx[4] ={1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int answer;
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        vector <int> curves;
        int x, y ,d, g;
        cin >> x >>y >> d >>g;
        curves.push_back(d);
        for(int j=0 ; j<g; j++){
            for(int k=curves.size()-1; k>=0; k--){
                curves.push_back((curves[k]+1)%4);
            }
        }
        a[y][x] = 1;
        for(int i=0; i<curves.size(); i++){
            x += dx[curves[i]];
            y += dy[curves[i]];
            //if(x<0 || x>=101 || y<0 || y>=101) continue;
            a[y][x] = 1;
        }
    }
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(a[i][j] ==1 && a[i+1][j]==1 && a[i][j+1] ==1 && a[i+1][j+1] == 1){
                answer+=1;
            }
        }
    }
    cout << answer << '\n';
    return 0;
}