#include <bits/stdc++.h>
#define MAX 987654321;
using namespace std;
int n, m, k, l, p;
bool is_trap[10001];
// 눌린 횟수, 현재 상태, 
int dist[11][3][10001];

struct edge {
    int to;
    int weight;
    int type;
};

struct info {
    int vertex;
    int dist;
    int pressed;
    bool state;
    info (int x, int y, int z, bool w) : vertex(x), dist(y), pressed(z), state(w) {}
};

bool operator<(const info &i1, const info &i2) {
    return i1.dist > i2.dist;
}

vector<vector<edge>> v;

void dijkstra(int x) {
    info f(x, 0, 0, false);
    priority_queue<info> pq;
    pq.push(f);
    dist[0][0][x] = 0;
    while(!pq.empty()) {
        auto pp = pq.top();
        pq.pop();
        int current_vertex = pp.vertex;
        int current_pressed = pp.pressed;
        int current_state = pp.state == true ? 1 : 0;
        for (int i = 0 ; i < v[current_vertex].size() ; i++) {
            auto sth = v[current_vertex][i];
            int next = sth.to;
            int next_pressed = current_pressed;
            int next_state = current_state;
            if (is_trap[next]) {
                if (current_pressed == p-1) {
                    next_pressed = 0;
                    next_state = !current_state;
                }
                else {
                    next_pressed = current_pressed + 1;
                }
            }
            int current_weight;
            if (sth.type == 0) {
                current_weight = sth.weight;
            }
            if (sth.type == 1) {
                if (!next_state) {
                    current_weight = sth.weight;
                }
                else current_weight = MAX;
            }
            if (sth.type == 2) {
                if (next_state) {
                    current_weight = sth.weight;
                }
                else current_weight = MAX;
            }
            if (next == 3)
                printf("%d %d %d %d %d %d %d\n", next_pressed, next_state, next, current_pressed, current_state, current_vertex, dist[current_pressed][current_state][current_vertex] + current_weight);
            if (dist[next_pressed][next_state][next] > dist[current_pressed][current_state][current_vertex] + current_weight) {
                dist[next_pressed][next_state][next]  = dist[current_pressed][current_state][current_vertex] + current_weight;
                info ff(next, dist[next_pressed][next_state][next], next_pressed, next_state);
                pq.push(ff);
                
            }
        }
    }
}


int main() {
    scanf("%d %d %d %d %d", &n, &m, &k, &l, &p);
    for (int i = 0 ; i < k ; i++) {
        int t;
        scanf("%d", &t);
        is_trap[t] = true;
    }
    v.resize(n+1);
    for (int i = 0 ; i < m - l ; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge e;
        e.to = b;
        e.weight = c;
        e.type = 0;
        v[a].push_back(e);
    }
    for (int i = 0 ; i < l ; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge e;
        e.to = b;
        e.weight = c;
        e.type = 1;
        v[a].push_back(e);
        edge e2;
        e2.to = a;
        e2.weight = c;
        e2.type = 2;
        v[b].push_back(e2);
    }
    int start, end;
    scanf("%d %d", &start, &end);
    for (int i = 0 ; i <= 10 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            for (int tt = 0 ; tt <= 10000 ; tt++) {
                dist[i][j][tt] = MAX;
            }
        }
    }
    dijkstra(start);
    int answer = MAX;
    for (int i = 0 ; i < p ; i++) {
        answer = min(answer, dist[i][0][end]);
        answer = min(answer ,dist[i][1][end]);
        printf("%d %d %d\n",i, dist[i][0][end], dist[i][1][end]);
    }
    if (answer == 987654321) {
        answer = -1;
    }
    printf("%d\n", answer);
    return 0;
}