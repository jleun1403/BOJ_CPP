#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int from;
    int to;
    int cost;
};
int dist[501];
int MAX = 987654321;
vector<Edge> a; 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, w;
        cin >> n>> m>> w;
        a.clear();
        memset(dist, 0, sizeof(dist));
        for(int i=0; i<m; i++){
            int x, y, z;
            cin >> x >> y >> z;
            Edge e;
            e.from = x;
            e.to = y;
            e.cost = z;
            a.push_back(e);
            e.from = y;
            e. to = x;
            e. cost = z;
            a.push_back(e);
        }
        for(int i=0; i<w; i++){
            Edge e;
            int x, y, z;
            cin >> x >> y >> z;
            e.from = x;
            e.to = y;
            e.cost = -z;
            a.push_back(e);
        }
        for(int i=1; i<=n ; i++){
            dist[i] = MAX;
        }
        //cout << " ** " << a.size() << '\n';
        dist[1] = 0;
        bool iscycle = false;
        for(int i=1; i<=n; i++){
            for(int j=0; j<a.size(); j++){
                int x = a[j].from;
                int y = a[j]. to;
                int z = a[j]. cost;
                if(dist[x] != MAX && dist[y] > dist[x] + z ){
                    dist[y] = dist[x] + z;
                    if(i == n) iscycle = true;
                }
            }
        }
        if(iscycle == true){
            printf("YES\n");
        }
        else printf("NO\n");
    }

    return 0;
}
