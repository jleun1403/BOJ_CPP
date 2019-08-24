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

int main() {
    string st;
    cin >> st;
    stack<char> s;
    s.push(st[0]);
    int ans = 10;
    for (int i = 1 ; i < st.length() ; i++) {
        if (s.top() == st[i])
            ans += 5;
        else
            ans += 10;
        s.push(st[i]);
    }
    printf("%d", ans);

















  return 0;
}
