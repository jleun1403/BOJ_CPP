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
    string s1, s2;
    cin >> s1 >>s2;
    stack<pair<char, int>> s;
    int l1 = s1.length();
    int l2 = s2.length();
    for (int i = 0 ; i < l1 ; i++) {
        int decide;
        for (decide = 0 ; decide < l2 ; decide++) {
            if (s2[decide] == s1[i])
                break;
        }
        if (s.empty() || ((decide != 0) && s.top().first == s2[decide - 1] && s.top().second == decide - 1))
            s.push(make_pair(s1[i], decide));
        else if (decide == 0) {
            s.push(make_pair(s1[i], 0));
        }
        else
            s.push(make_pair(s1[i], l2));
        if (s.top().second == (l2-1)){
            for (int p = 0 ; p < l2 ; p++)
                s.pop();
        }

    }
    if (s.empty())
        cout << "FRULA";
    else {
        string ans = "";
        while (!s.empty()) {
            ans += s.top().first;
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }








  return 0;
}
