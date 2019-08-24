#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int to;
    int cost;
};
vector <Edge> a[1001];
int dist[1001];
bool check[1001];
int MAX = 987654321;
int main(){
    int n, m;
    cin >> n;
    cin >> m;
    for(int i=0; i<m; i++){
        int x , y, z;
        cin >> x >> y >> z;
        Edge e;
        e.to = y;
        e.cost = z;
        a[x].push_back(e);
    }
    int start, end;
    cin >> start >> end;
    for(int i = 1; i<=n ; i++){
        dist[i] = MAX;
    }
    dist[start] = 0;
    for(int k=0; k<n-1; k++){
        int m = MAX +1;
        int x= -1;
        for(int i=1; i<=n; i++){
            if(check[i] == false && m > dist[i]){
                m = dist[i];
                x = i;
            }
        }
        check [x] = true;
        for(int i=0; i< a[x]. size(); i++){
            int y = a[x][i].to;
            if(dist[y]  >dist[x] + a[x][i].cost){
                dist[y] = dist[x] + a[x][i].cost;
            }
        }
    }
    printf("%d\n", dist[end]);
    return 0;
}