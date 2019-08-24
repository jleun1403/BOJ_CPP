#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int from;
    int to;
    int cost;
};
int dist[501];
int MAX = 987654321;
int main(){
    int n, m;
    cin >> n>> m;
    vector <Edge> a(m);
    for(int i=0; i<m; i++){
        cin >> a[i].from >> a[i].to >> a[i].cost ;
    }
    for(int i=1; i<=n; i++){
        dist[i] = MAX;
    }
    dist[1] = 0;
    bool iscycle = false;
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            int x = a[j].from;
            int y = a[j].to;
            int z = a[j].cost;
            if(dist[x]!= MAX && dist[y] > dist[x] +z){
                dist[y] = dist[x] + z;
                if(n== i) 
                iscycle = true;
            }
        }
    }
    if(iscycle == true){
        printf("-1\n");
    }
    else{
        for(int i=2; i<=n; i++){
            if(dist[i] == MAX)
                dist[i] = -1;
            printf("%d\n", dist[i]);
            
        }
    }
    return 0;
}
