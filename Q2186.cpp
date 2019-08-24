#include <bits/stdc++.h>
using namespace std;
int n , m , k, leng;
char a[101][101];
char ans[90];
int answer;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void dfs(int i, int j, int index, int cnt){
    int x = i;
    int y = j;
    if(index == leng+1 && cnt <=k) {
        answer +=1;
        return;
    }
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <0 || nx >=n || ny <0 || ny>=m) continue;
        if(a[nx][ny] == )
    }
}
int main(){
    cin >> n>> m>> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("% c", &a[i][j]);
        }
    }
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        ans[i] = s[i];
    }
    leng = s.size();
    queue <pair<int,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == ans[0]) q.push(make_pair(i,j));
        }
    }
    while(!q.empty()){
        int x= q.front().first;
        int y= q.front().second;
        q.pop();
        dfs(x,y, 1, 0);
    }
}