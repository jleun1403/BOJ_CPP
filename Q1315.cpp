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

struct q {
    int s, i, p;
};
bool d[1001][1001];
int point[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<q> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].s >> v[i].i >> v[i].p;
    }
    int ans = 0;
    for (int i = 1 ; i <= 1000 ; i++) {
        for (int j = 1 ; j <= 1000 ; j++) {
            point[i][j] = 2 - i - j;
            int cnt = 0;
            for (int k = 0 ; k < n ; k++) {
                if (v[k].s <= i || v[k].i <= j) {
                    point[i][j] += v[k].p;
                    cnt++;
                }
            }
            if (i == 1 && j == 1)
                d[i][j] = true;
            else if (i > 1 && point[i-1][j] > 0 && d[i-1][j])
                d[i][j] = true;
            else if (j > 1 && point[i][j-1] > 0 && d[i][j-1])
                d[i][j] = true;
            if (d[i][j])
                ans = max(ans, cnt);
        }
    }
    cout << ans;














  return 0;
}
