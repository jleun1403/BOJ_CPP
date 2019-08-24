#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int> a[101];
int d[101];
vector <pair<int,int>> answer;
bool cmp(const pair<int,int>  &a, const pair<int,int> &b){
    if(a.first <=b.first){
        if(a.first == b.first){
            if( a.second <b.second) return true;
            else return false;
        }
        else return true;
    }
    else return false;
}
int go(int x){
    int cnt = 0;
    queue <int> q;
    q.push(x);
    d[x] = 1;
    while(!q.empty()){
    int now = q.front() ;
    q.pop();
    for(int i=0; i<a[now].size(); i++){
        int y = a[now][i];
        if(d[y]==0){
            d[y] = d[now] + 1;
            q.push(y);
            }
        } 
    }
    for(int i=1; i<=n; i++){
        cnt+=d[i];
    }
    cnt-=1;
    return cnt;
}
int main(){
    cin >> n>> m;
    int x, y;
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &x, &y);
            a[x].push_back(y);
            a[y].push_back(x);
    }
    for(int i=1; i<=n; i++){
        memset(d, 0, sizeof(d));
        answer.push_back(make_pair(go(i), i));
    }
    sort(answer.begin(), answer.end(), cmp);
    printf("%d\n", answer[0].second);
    return 0;
}