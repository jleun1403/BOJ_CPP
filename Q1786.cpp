#include <bits/stdc++.h>

using namespace std;


vector<int> failure_function (const string &s){
    int m = s.size();
    vector<int> pi(m);
    int begin = 1;
    int matched = 0;

    while(begin + matched < m) {
        if (s[begin + matched ] == s[matched]) {
            matched += 1;
            pi[begin+matched - 1] = matched;
        }
        else {
            if (matched == 0)
                begin += 1;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

vector<int> KMP(const string &s1, const string &s2) {
    int n = s1.size();
    int m = s2.size();
    vector<int> pi = failure_function(s2);
    vector<int> ret;
    int begin = 0, matched = 0;
    while(begin <= n - m) {
        if (matched < m && s1[begin + matched] == s2[matched]) {
            matched += 1;
            if (matched == m) {
                ret.push_back(begin);
            }
        }
        else {
            if (matched ==0)
                begin += 1;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    vector<int> ans = KMP(s1, s2);
    printf("%d\n", ans.size());
    for (int i = 0 ; i < ans.size() ; i++) {
        printf("%d ", ans[i] + 1);
    }
    return 0;
}