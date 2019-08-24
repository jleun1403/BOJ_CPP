#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int to;
    int cost;
};
vector <Edge> v[801];
int dist[801];
bool check[801];
int MAX = 100000000;
int n, m;
void solve(int start){
    for(int i=1; i<=n; i++){
        dist[i] = MAX;
        check[i] = false;
    }
    dist[start] = 0;
    for(int k=0; k<n-1; k++){
        int m = MAX +1;
        int x = -1;
        for(int i=1; i<=n; i++){
            if(check[i] == false && dist[i] < m){
                m = dist[i];
                x = i;
            }
        }
        check[x] = true;
        for(int i=0; i<v[x].size(); i++){
            int y = v[x][i].to;
            if(dist[y] > dist[x] + v[x][i].cost){
                dist[y] = dist[x] + v[x][i].cost;
            }
        }
    }
}
int main(){
    cin >> n>> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>> a>> b >> c;
        Edge e;
        e.to = b;
        e.cost = c;
        v[a].push_back(e);
        e.to = a;
        e.cost =c;
        v[b].push_back(e);
    }
    /*for(int i=1; i<=n; i++){
        dist[i] = MAX;
    }*/
    int v1, v2;
    cin >>v1 >> v2;
    solve(1);
    int x1 = dist[v1];
    int y1 = dist[v2];
    solve(v1);
    int x2 = dist[v2];
    int y2 = dist[n];
    solve(v2);
    int y3 =dist[v1];
    int x3 = dist[n];

    int ans1, ans2, ans;
    ans1 = x1 + x2 + x3;
    ans2 = y1 + y2 + y3;
    ans = 0;
    if(ans1 >= MAX || ans2 >=MAX) {
        ans = -1;
    }
    else{
        if(ans1 > ans2)
        ans = ans2;
        else ans = ans1;
    }
    
    printf("%d\n", ans);
    return 0;
}