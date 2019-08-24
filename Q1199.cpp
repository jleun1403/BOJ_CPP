#include <bits/stdc++.h>

using namespace std;

int adj[1000][1000];
int degree[1000];
vector<int> ans;
int n;
queue<int> q;

bool possible() {
    for (int i = 0 ; i < 1000 ; i++) {
        if (degree[i] % 2) return false;
    }
    return true;
}



void eulerian_circuit(int x) {
    for (int i = 0 ; i < n ; i++) {
        while(adj[x][i] > 0) {
            adj[x][i] -= 1;
            adj[i][x] -= 1;
            eulerian_circuit(i);
        }
    }
    ans.push_back(x);
}

int main() {

    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            scanf("%d", &adj[i][j]);
            if (i > j) {
                degree[i] += adj[i][j];
                degree[j] += adj[i][j];
            }
        }
    }
    if (!possible()) {
        printf("-1");
        return 0;
    }
    eulerian_circuit(0);
    reverse(ans.begin(), ans.end());
    for (int i = 0 ; i < ans.size() ; i++) {
        printf("%d ", ans[i] + 1);
    }
    return 0;
}