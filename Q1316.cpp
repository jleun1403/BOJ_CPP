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

using namespace std;
int n;
int c[26];
int main() {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0 ; i <n ; i++) {
        string s;
        cin >> s;
        if (s.length() == 1) {
            ans++;
            continue;
        }
        c[s[0]- 'a'] = 1;
        bool flag = true;
        for (int j = 1 ; j < s.length() ; j++) {
            if (c[s[j] - 'a'] == 0) {
                c[s[j]- 'a'] = 1;
            }
            else {
                if (s[j-1] != s[j])
                    flag = false;
            }
        }
        if (flag)
            ans++;
        memset(c, 0, sizeof(c));
    }
    printf("%d", ans);
















  return 0;
}
