#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<int> checked;
vector<vector<int>> v;

int DFS(int node){
    checked[node] = 1;
    for (int i = 0 ; i < v[node].size() ; i++) {
        if (checked[v[node][i]] == 0)
            DFS(v[node][i]);
    }
}

bool full(vector<int> c) {
    for (int i = 1 ; i < c.size() ; i++) {
        if (c[i] == 0)
            return false;
    }
    return true;
}

int main(){

    int n;
    int m;
    int count = 0;
    cin >> n >> m;
    checked.resize(n+1, 0);
    v.resize(n+1);
    for (int i = 0 ; i < m ; i++) {
        int from;
        int to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);

    }
    for (int i = 1 ; i <= n ; i++)
        sort(v[i].begin(), v[i].end());
    int i = 0;
    for (int i = 1 ; i <= n ; i++){
        if (checked[i] == 0){
            DFS(i);
            count++;
        }
    }
    cout << count;

}


