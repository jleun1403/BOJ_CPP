#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>
#define inf 987654321

using namespace std;
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    string s = to_string(n);
    string ans = to_string(n);
    for (int i = 1 ; i < n ; i++) {
        ans += s;
        if (ans.length() > 3000)
            break;
    }
    cout << ans.substr(0, m);
















  return 0;
}
