#include <bits/stdc++.h>
using namespace std;
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
vector<int> v;
int a[101][101];
int answer;
int main(){
    cin >> n;
    for(int k=0; k<n; k++){
        v.clear();
        int x, y, d, g;
        scanf("%d %d %d %d", &x, &y, &d, &g);
        v.push_back(d);
        
        for(int i=0; i<g; i++){
            for(int j = v.size()-1; j>=0; j--){
                v.push_back((v[j]+1)%4);
            }
        }
        a[y][x] = 1;
        for(int i=0; i<v.size(); i++){
            x +=dx[v[i]];
            y +=dy[v[i]];
           if(x>=0 && x<=100 && y>=0 && y<=100) 
           a[y][x] = 1;
            
        }
    }
    for(int i=0; i<100; i++){
        for(int j=0; j< 100; j++){
            if(a[i][j]==1 && a[i+1][j] ==1 && a[i][j+1] ==1 && a[i+1][j+1] ==1){
                answer+=1;
            }
        }
    }
    cout << answer << '\n';
    return 0;
        
}