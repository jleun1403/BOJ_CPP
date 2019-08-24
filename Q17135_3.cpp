#include <bits/stdc++.h> // 10:46
using namespace std;
int n, m, d;   
int a[17][17];
int a_copy[17][17];
int answer;
vector <int> v;
int dist(int x1, int y1, int x2, int y2){
    return abs(x1-x2)+ abs(y1-y2);
}
void move(){
    for(int i=n-1; i>=1; i--){
        for(int j=0; j<m; j++){
            a_copy[i][j] = a_copy[i-1][j];
        }
    }
    for(int j=0; j<m; j++){
        a_copy[0][j] = 0;
    }
}
void go(){
    for(int i=0; i<n; i++){
        for(int j=0 ; j<m; j++){
            a_copy[i][j] = a[i][j];
        }
    }
    int ans = 0;
    int row = 0;
    while(true){
        queue <pair<int,int>> q;
        for(int k=0; k<v.size(); k++){
            int x = n;
            int y = v[k];
            int mindist= 987654321;
            bool ok = false;
            for(int j=0; j<m; j++){
                for(int i=0; i<n; i++){
                    if(a_copy[i][j] ==1 && dist(x,y,i,j) <=d){
                        mindist = min(mindist, dist(x,y,i,j));
                    }
                }
            }
            for(int j=0; j<m; j++){
                for(int i=n-1; i>=0; i--){
                    if(dist(x,y,i,j) == mindist && a_copy[i][j] == 1){
                        q.push(make_pair(i,j));
                        ok = true;
                        break;
                    }
                }
                if(ok == true) break;
            } 
        }
        while(!q.empty()){
            int x= q.front().first;
            int y= q.front().second;
            q.pop();
            if(a_copy[x][y] == 1){
                a_copy[x][y] =0;
                ans +=1;
            }
            else continue;
        }
        move();
        row +=1;
        if(row == n){
            answer= max(ans, answer);
            break;
        }
    }
}
int main(){
    cin >> n>> m>> d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i=0; i<m-2; i++){
        for(int j=i+1; j<m-1; j++){
            for(int k=j+1; k<m; k++){
                v.push_back(i);
                v.push_back(j);
                v.push_back(k);
                go();
                v.clear();
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}