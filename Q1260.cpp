#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> checkd;
vector<int> checkb;
vector<vector<int>> v;
queue<int> q;

void DFS(int start) {
    checkd[start] = 1;
    cout << start <<' ';
    for (int i = 0 ; i < v[start].size(); i++){
        if (checkd[v[start][i]] == 0)
            DFS(v[start][i]);
    }
}

void BFS(int start) {
    checkb[start] = 1;
    cout << start << ' ';
    q.push(start);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0 ; i < v[x].size() ; i++){
            if (checkb[v[x][i]] == 0){
                checkb[v[x][i]] = 1;
                q.push(v[x][i]);
                cout << v[x][i] << ' ';
            }
        }
    }
}
int main(){

    int n;
    int m;
    int start;
    cin >> n >> m >> start;
    v.resize(n+1);
    checkb.resize(n+1, 0);
    checkd.resize(n+1, 0);
    for (int i = 0 ; i < m ; i++){
        int from;
        int to;
        cin >>from >>to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    for (int i = 1 ; i <= n ; i++){
        sort(v[i].begin(), v[i].end());
    }
    DFS(start);
    cout << '\n';
    BFS(start);


}
