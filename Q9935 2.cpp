#include <bits/stdc++.h>

using namespace std;

stack<pair<int, int>> s;
map<int, char> m;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s2.length();
    for (int i = 0 ; i < n ; i++) {
        m[i+1] = s2[i];
    }
    int t = s1.length();
    for (int i = 0 ; i < t;  i++) {
        if (s.empty()) {
            if (s1[i] == s2[0]) {
                s.push(make_pair(s1[i], 1));
            }
            else s.push(make_pair(s1[i], 0));
        }
        else {
            char c = s1[i];
            /*if (c == s2[0]) {
                s.push(make_pair(s1[i], 1));
            }*/
            if (c == m[s.top().second+1]) {
                s.push(make_pair(s1[i], s.top().second + 1));
            }
            else s.push(make_pair(s1[i], 0));
        }

        if (s.top().second == n) {
            for (int k = 0 ; k < n ; k++) {
                s.pop();
            }
        }
    }
    if (s.empty()) {
        cout << "FRULA" << '\n';
    }
    else {
        stack<char> t;
        while(!s.empty()) {
            t.push(s.top().first);
            s.pop();
        }
        while(!t.empty()) {
            cout << t.top();
            t.pop();
        }
    }

    return 0;
}