    #include <vector>
    #include <iostream>
    #include <queue>
    #include <cstring>
    #define inf 987654321
    using namespace std;

    int n;
    const int source = 0;
    const int drain = 366;
    vector<vector<int>> v;
    int cap[367][367];
    int flow[367][367];
    int cost[367][367];
    int dist[367];
    int pre[367];
    bool inque[367];

    int main(){
        while(true) {
            scanf("%d", &n);
            v.resize(367);
            if (n == 0)
                return 0;
            memset(cap, 0, sizeof(cap));
            memset(cost, 0, sizeof(cost));
            memset(flow, 0, sizeof(flow));
            for (int i = 0 ; i < n ;i++) {
                int from, to, weight;
                scanf("%d %d %d", &from, &to, &weight);
                v[from].push_back(to+1);
                v[to+1].push_back(from);
                cost[from][to+1] = -weight;
                cost[to+1][from] = weight;
                cap[from][to+1] = 1;
            }
            for (int i = 0 ; i <= 365 ; i++) {
                cap[i][i+1] = 2;
                v[i].push_back(i+1);
                v[i+1].push_back(i);
            }
            int ans = 0;
            while (true) {
                memset(pre, -1, sizeof(pre));
                memset(inque, false, sizeof(inque));
                fill(dist, dist+367 , inf);
                queue<int> q;
                dist[source] = 0;
                inque[source] = true;
                q.push(source);
                while(!q.empty()){
                    int cur = q.front();
                    inque[cur] = false;
                    q.pop();
                    for (int i = 0 ; i < v[cur].size(); i++) {
                        int next = v[cur][i];
                        if (cap[cur][next] > flow[cur][next] && dist[next] > dist[cur] + cost[cur][next]) {
                            dist[next] = dist[cur] + cost[cur][next];
                            pre[next] = cur;
                            if (inque[next] == false){
                                inque[next] = true;
                                q.push(next);
                            }
                        }
                    }
                }
                if (pre[drain] == -1)
                    break;
                int f = inf;
                for (int i = drain ; i != source ; i = pre[i]) {
                    f = min(f, cap[pre[i]][i] - flow[pre[i]][i]);
                }
                for (int i = drain ; i != source ; i = pre[i]) {
                    flow[pre[i]][i] += f;
                    flow[i][pre[i]] -= f;
                    ans += (f * (cost[pre[i]][i]) * -1);
                }

            }
            printf("%d\n", ans);
            v.clear();
        }














    }
