#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int to;
    int cost;
};
vector <Edge> v[1001];
int dist[1001];
bool check[1001];
int MAX = 987654321;
int from[1001];

int main(){
    int n , m;
    cin >> n;
    cin >> m;
    vector <int> ans;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        Edge e;
        e.to = b;
        e.cost = c;
        v[a].push_back(e);
    }
    int start, end;
    cin >> start >> end;

    for(int i=1; i<=n; i++){
        dist[i] = MAX;
    }
    dist[start] = 0;
    from[start] = -1;
    for(int k=0; k<n-1; k++){
        int m = MAX +1;
        int x = -1;
        for(int i=1; i<=n; i++){
            if(check[i] == false && dist[i] < m){
                m = dist[i];
                x= i;
            }
        }
        check[x] = true;

        for(int i=0; i< v[x].size(); i++){
            int y = v[x][i].to;
            if(dist[y] > dist[x] + v[x][i].cost){
                 dist[y] = dist[x] + v[x][i]. cost;
                 from[y] = x;
             }
        }
        
    }
    cout << dist[end] << '\n';
    int x = end;
    while(x!=-1){
        ans.push_back(x);
        x = from[x];
    }
    cout << ans.size() << '\n';
    for(int i=ans.size()-1; i>=0; i--){
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}