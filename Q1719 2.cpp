#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int n, m;
int dist[201][201];
int go[201][201];
vector<vector<pair<int, int>>>connected;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >>m;
    connected.resize(n+1);
    for (int i = 1; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            if (i != j)
                dist[i][j] = inf;
        }
    }
    for (int i = 0 ; i <m ; i++) {
        int a, b, c;
        cin >> a>> b >> c;
        dist[a][b] = c;
        dist[b][a] = c;
        go[a][b] = b;
        go[b][a] = a;
        connected[a].push_back(make_pair(b, c));
        connected[b].push_back(make_pair(a, c));
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            for (int k = 1 ; k<= n ; k++) {
                if(dist[j][k] > dist[j][i] + dist[i][k]) {
                    dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }
    for (int i = 1 ; i<= n ; i++){
        for (int j = 1 ; j <= n ; j++) {
            if (i == j) printf("- ");
            else {
                for (int k = 0 ; k < connected[i].size() ; k++) {
                    if (dist[i][j] == connected[i][k].second + dist[connected[i][k].first][j]) {
                        printf("%d ", connected[i][k].first);
                        break;
                    }
                }
            }
        }
        printf("\n");
    }















  return 0;
}
