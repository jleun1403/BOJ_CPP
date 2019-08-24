#include <bits/stdc++.h>
using namespace std;
 int dist[10001];
bool check[10001];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, start;
        scanf("%d %d %d", &n, &m, &start);
        vector<pair<int,int>> v[10001];
        memset(dist, 0, sizeof(dist));
        memset(check, false, sizeof(check));
        for(int i=0; i<m; i++){
            int to, from, cost;
            scanf("%d %d %d", &to, &from, &cost);
            v[from].push_back(make_pair(to, cost));
        }
        for(int i=1; i<=n; i++){
            dist[i] = 987654321;
        }
        dist[start] = 0;
        for(int k=0; k<n; k++){
            int m = 987654322;
            int x= -1;
            for(int i=1; i<=n; i++){
                if(check[i] == false && dist[i] < m){
                    m = dist[i];
                    x = i;
                }
            }
            check[x] = true;
            for(int i=0; i<v[x].size(); i++){
                int y= v[x][i].first;
                if(dist[y] > dist[x] + v[x][i].second)
                    dist[y] = dist[x] + v[x][i].second;
            }
        }
        int answer= 0;
        int cnt = 0;
        for(int i=1; i<=n; i++){
            if(check[i] == true && dist[i] !=987654321) {
                cnt+=1;
                answer= max(answer, dist[i]);
            }
        }
        printf("%d %d\n", cnt, answer); 
    }
    return 0;
}