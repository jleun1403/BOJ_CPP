#include <bits/stdc++.h>
using namespace std;
bool check[1001];
int dist[1001];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector <pair<int,int >> v[1001];
    for(int i=0; i<m; i++){
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        v[from].push_back(make_pair(to, cost));
    }
    memset(dist, 0, sizeof(dist));
    memset(check, false, sizeof(check));
    for(int i=1; i<=n; i++){
        dist[i] = 987654321;
    }
    dist[1] = 0;
    for(int k=0; k<n; k++){
        int m = 987654322;
        int x = -1;
        for(int i=1; i<=n; i++){
            
        }
    }

}