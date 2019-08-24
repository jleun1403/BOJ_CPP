#include <bits/stdc++.h>
using namespace std;
vector <pair<int,int>> v[1001];
bool check[1001];
int d[1001];
int parent[1001];
vector <pair<int,int >> answer;
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b ,c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    for(int i=1; i<=n; i++) d[i] = 987654321; // 초기화 

    priority_queue <pair<int,int>> q;
    q.push(make_pair(0,1));
    d[1] = 0;
    while(!q.empty()){
        int cost= -q.top().first;
        int now = q.top().second;
        q.pop();
        sort(v[now].begin(), v[now].end());
        for(int i=0; i<v[now].size(); i++){ 
           int next = v[now][i].first;
           int ncost= v[now][i].second;
           if(d[next] > d[now] + ncost){
               d[next] = d[now] + ncost;
               q.push(make_pair(-d[next], next));
               parent[next] = now;
           }
        }
    }
    cout << n-1 << '\n';
    for(int i=2; i<=n;  i++){
        printf("%d %d\n", parent[i], i);
    }
    return 0;
}