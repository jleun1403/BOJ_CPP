#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int n, t;
vector<int> group;

bool compare(int a, int b) {
    if (group[a] != group[b]) return group[a] < group[b];
    else return group[a+t] < group[b+t];
}
vector<int> suffix_array(const string &s) {
    n = s.length();
    t = 1;
    group.resize(n+1);
    for (int i = 0 ; i < n ; i++) {
        group[i] = s[i];
    }
    group[n] = -1;

    vector<int> perm(n);
    for (int i = 0 ; i < n ; i++) {
        perm[i] = i;
    }
    while(t < n ) {
        sort(perm.begin(), perm.end(), compare);
        if (t*2 >= n)
            break;
        vector<int> newGroup(n+1);
        newGroup[n] = -1;
        newGroup[perm[0]] = 0;
        for (int i = 1 ; i< n ; i++){
            if (compare(perm[i-1], perm[i]))
                newGroup[perm[i]] = newGroup[perm[i-1]] + 1;
            else newGroup[perm[i]] = newGroup[perm[i-1]];
        }
        group = newGroup;
        t *= 2;
    }
    return perm;

}


int main() {
    string s;
    cin >> s;
    int k = s.length();
    vector<int> ans = suffix_array(s);
    for (int i = 0 ; i < k ; i++) {
        printf("%d\n", ans[i]);
    }
















  return 0;
}
