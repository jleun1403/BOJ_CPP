#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

vector<vector<pair<int, int>>> v;
int n, m;
int dist1[4001];
int dist2[4001][2];

void dijkstra1() {
    for (int i = 2 ; i <= n ; i++)
        dist1[i] = inf;
    dist1[1] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, 1));
    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int cur = p.second;
        int cur_dist = -p.first;
        if (cur_dist > dist1[cur])
            continue;
        for (int i = 0 ; i < v[cur].size() ; i++) {
            int next = v[cur][i].first;
            int dist = v[cur][i].second;
            if (dist1[next] > dist1[cur] + dist) {
                dist1[next] = dist1[cur] + dist;
                pq.push(make_pair(-dist1[next], next));
            }
        }
    }
}

void dijkstra2() {
    for (int i = 2 ; i<= n ; i++) {
        dist2[i][0] = dist2[i][1] = inf;
    }
    dist2[1][0] = 0;
    dist2[1][1] = inf;
    // dist vertex chance 거리 정점 2배속찬스
    priority_queue<pair<pair<int,int>,int>> pq;
    pq.push({{0, 1}, 0});
    while(!pq.empty()) {
        auto p = pq.top();
        int cur_dist = -p.first.first;
        int cur = p.first.second;
        //printf("%d\n", cur);
        pq.pop();
        int chance = p.second;
        if (cur_dist > dist2[cur][chance])
            continue;
        for (int i = 0 ; i < v[cur].size() ; i++) {
            int next = v[cur][i].first;
            int go = v[cur][i].second;
            if (chance == 0) {
                go /= 2;
                if (dist2[next][1] > dist2[cur][0] + go) {
                    dist2[next][1] = dist2[cur][0] + go;
                    pq.push({{-dist2[next][1], next}, 1});
                }
            }
            else {
                go *= 2;
                if (dist2[next][0] > dist2[cur][1] + go) {
                    dist2[next][0] = dist2[cur][1] + go;
                    pq.push({{-dist2[next][0], next}, 0});
                }
            }
        }
    }
}


int main() {
    scanf("%d %d", &n, &m);
    v.resize(n+1);
    for (int i = 0 ; i < m ; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(make_pair(b, c*2));
        v[b].push_back(make_pair(a, c*2));
    }
    dijkstra1();
    dijkstra2();
    /*for (int i = 1 ;i <= n ; i++) {
        printf("%d\n", dist1[i]);
    }
    for (int i = 1 ; i <= n ; i++) {
        printf("%d\n", min(dist2[i][1], dist2[i][0]));
    }*/
    int cnt = 0;
    for (int i = 1 ; i <= n ; i++) {
        if (dist1[i] < min(dist2[i][1], dist2[i][0]))
            cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}