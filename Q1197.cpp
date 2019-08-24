#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int start;
    int end;
    int cost;
};
bool cmp (const Edge &e1, const Edge &e2){
    return e1.cost < e2.cost;
}
int p[10001];
int Find(int x){
    if(x == p[x]){
        return x;
    }
    else return p[x] = Find(p[x]);
}
void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    p[x] = y;
}
int main(){
    int n, m;
    cin >> n>> m;
    for(int i=1; i<=n; i++){
        p[i] = i;
    }
    vector <Edge> a(m);
    for(int i=0; i<m; i++){
        cin >> a[i].start >> a[i].end >> a[i].cost ;
    }
    sort(a.begin(), a.end(), cmp);
    int ans=0;
    for(int i=0; i<m; i++){
        Edge e = a[i];
        int x = Find(e.start);
        int y = Find(e.end);
        if(x != y){
            Union(e.start, e.end);
            ans +=e.cost;
        }
    }
    cout << ans << '\n';
    return 0;
}