#include <iostream>
#include <vector>

using namespace std;

int main(){
    int testcase;
    cin >>testcase;
    while(testcase--) {
        int n;
        cin >> n;
        vector<vector<int>> v(n+1);
        for (int i = 1 ; i <= n ; i++) {
            int from = i;
            int to;
            cin >> to;
            v[from].push_back(to);
        }
        int cnt = 0;
        vector<int> visited(n+1, 0);
        for (int i = 1 ; i <= n ; i++) {
            int start = i;
            if (visited[start] == 0) {
                visited[start] = 1;
                int s = v[start][0];
                while (s != start) {
                    visited[s] = 1;
                    s = v[s][0];
                }
                cnt++;
            }
        }
        cout << cnt << '\n';

    }
}
