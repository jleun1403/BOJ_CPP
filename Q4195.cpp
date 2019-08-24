#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
map<string , string> parent;
map<string, int> group;

string Find(string s) {
    if (parent[s] == s)
        return s;
    return parent[s] = Find(parent[s]);
}

void Union(string s1, string s2) {
    s1 = Find(s1);
    s2 = Find(s2);
    if (s1 == s2)
        return;
    parent[s2] = s1;
    group[s1] += group[s2];
}

int main() {
    ios_base::sync_with_stdio(false);
    int testcase;
    cin >> testcase;
    while(testcase--) {
        int n;
        cin >> n;
        for (int i = 0 ; i < n ; i++) {
            string f1, f2;
            cin >> f1 >> f2;
            if (parent[f1] == "") {
                parent[f1] = f1;
                group[f1] = 1;
            }
            if (parent[f2] == "") {
                group[f2] = 1;
                parent[f2] = f2;
            }
            if (f1 < f2) {
                swap(f1, f2);
            }
            Union(f1, f2);
            f1 = parent[f1];
            printf("%d\n", group[f1]);
        }
        parent.clear();
        group.clear();
    }
















  return 0;
}
