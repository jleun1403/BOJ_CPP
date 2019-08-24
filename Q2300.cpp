#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>
#define inf 987654321

using namespace std;
vector<pair<int, int>> v;
int dp[10001];
int dx[10001];
int dy[10001];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    v.push_back(make_pair(0, 0));
    for (int i = 0 ; i <n ; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin()+1, v.end());

    for (int i = 1 ; i<= 10000 ; i++) {
        dp[i] = inf;
    }
    for (int i =1 ; i<= n ; i++) {
        int up = 0;
        for (int j = i ; j >= 1; j--) {
            up = max(up, abs(v[j].second));
            int square = max(v[i].first - v[j].first, up*2);
            dp[i] = min(dp[i], dp[j-1] + square);
        }
    }
    cout << dp[n];














  return 0;
}
