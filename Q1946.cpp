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
    int testcase;
    vector<pair<int, int>> v;
    scanf("%d", &testcase);
    while(testcase--) {
        int n;
        v.clear();
        scanf("%d", &n);
        for (int i = 0 ; i < n ;i++) {
            int f, s;
            scanf("%d %d", &f, &s);
            v.push_back(make_pair(f, s));
        }
        sort(v.begin(), v.end());
        stack<pair<int ,int>> q;
        q.push(v[0]);
        for (int i = 1; i < n ; i++) {
            if (v[i].second < q.top().second) {
                q.push(v[i]);
            }
        }
        printf("%d\n", q.size());
        while(!q.empty())
            q.pop();
    }


















  return 0;
}
