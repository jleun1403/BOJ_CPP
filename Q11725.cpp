#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <vector<int>> a;
int c[100001];
int depth[100001];
int parent[100001];

void DFS(int x) {
    c[x] = 1;
    for (int p : a[x]){
        if (c[p] == 0){
            c[p] = 1;
            depth[p] = depth[x] + 1;
            parent[p] = x;
            DFS(p);
        }
    }
}

int main(){
    int n;
    cin >> n;
    a.resize(n + 1);
    for (int i = 0 ; i < n-1 ; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    parent[1] = 0;
    depth[1] = 0;
    DFS(1);
    for (int i = 2 ; i <= n ; i++){
        cout << parent[i] << '\n';
    }
    return 0;

}
