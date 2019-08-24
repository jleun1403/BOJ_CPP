#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v[20001];
int d[20001];
int main(){
    scanf("%d %d", &n , &m);
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        d[i] = 987654321;
    }
    d[1] = 0;
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int x =q.front();
        q.pop();
        for(int i=0; i<v[x].size(); i++){
            int y =v[x][i];
            if(d[y] > d[x]+1){
                d[y] = d[x] +1;
                q.push(y);
            }
        }
    }
    int maxnum = 0;
    for(int i=1; i<=n; i++){
        maxnum = max(maxnum, d[i]);
    }
    int cnt = 0;
    int minnum = 987654321;
    for(int i=1; i<=n; i++){
        if(d[i] == maxnum){
            cnt +=1;
            minnum = min(minnum, i);
        }
    }
    printf("%d %d %d\n", minnum, maxnum, cnt);
    cout<< '\n';
    return 0;
}