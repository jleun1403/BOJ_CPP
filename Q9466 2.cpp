#include <iostream>

using namespace std;

int a[100001];
int c[100001];

bool DFS(int node, int next) {
    c[node] = 1;
    if (node == next)
        return true;
    if (c[next] == 0) {
        c[next] = 1;
        return DFS(node, a[next]);
    }
    return false;
}
void restart(int b[], int n) {
    for (int i = 1 ; i <= n ; i++)
        b[i] = 0;
}

int main(){

    int testcase;
    cin >>testcase;
    while (testcase--) {
        int n;
        cin >> n;
        for (int i = 1 ; i <= n ; i++) {
            int k;
            cin >>k;
            a[i] = k;
        }
        int cnt = 0;
        for (int i = 1 ; i <= n ; i++) {
            if (!DFS(i, a[i]))
                cnt++;
        }
        cout << cnt <<'\n';


    }
    return 0;
}
