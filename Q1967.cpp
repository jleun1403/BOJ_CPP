#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> v;
int c[100001];
int d[100001];

void DFS(int x){
    for (pair<int, int> p : v[x]) {
        if (c[p.first] == 0) {
            c[p.first] = 1;
            d[p.first] = d[x] + p.second;
            DFS(p.first);
        }
    }
}



int main() {
    int n;
    cin >> n;
    v.resize(n+1);
    for (int i = 0 ; i < n-1; i++) {
        int vertex;
        cin >> vertex;
        int x;
        int y;
        scanf("%d", &x);
        scanf("%d", &y);
        v[vertex].push_back(make_pair(x, y));
        v[x].push_back(make_pair(vertex, y));
    }
    c[1] = 1;
    d[1] = 0;
    DFS(1);

    int maxindex = 1;
    for (int i = 1 ; i <= n ; i++) {
        if (d[maxindex] < d[i])
            maxindex = i;
    }


    for (int i = 1 ; i <= n ; i++) {
        c[i] = 0;
        d[i] = 0;
    }
    c[maxindex] = 1;
    d[maxindex] = 0;
    DFS(maxindex);

    int answer = 0;
    for (int i = 1; i <= n ; i++){
        if (answer < d[i])
            answer = d[i];
    }

    cout << answer;


}
