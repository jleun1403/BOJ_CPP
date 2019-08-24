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

int dp[51];
vector<vector<int>> child(51);

bool cmp(int a, int b) {
    return dp[a] > dp[b];
}

int time(int x) {

    if (dp[x] != -1)
        return dp[x];

    if (child[x].size() == 0)
        return dp[x] = 0;

    for (int i = 0 ; i < child[x].size() ; i++) {
        if(dp[child[x][i]] == -1)
            time(child[x][i]);
    }
    sort(child[x].begin(), child[x].end(), cmp);

    int ans = 0;

    for (int i = 0 ; i < child[x].size() ; i++) {
        ans = max(ans, dp[child[x][i]] + i + 1);
    }
    return dp[x] = ans;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        int parent;
        scanf("%d", &parent);
        if (i == 0)
            continue;
        child[parent].push_back(i);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d", time(0));


















  return 0;
}
