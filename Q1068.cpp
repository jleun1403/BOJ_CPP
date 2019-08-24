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

vector<vector<int>> v;
bool exist[50];
int n;

void e(int n) {
    exist[n] = false;
    for (int i = 0 ; i < v[n].size() ; i++) {
        e(v[n][i]);
    }
}

int main() {
    scanf("%d", &n);
    v.resize(n);
    memset(exist, true, sizeof(exist));
    for (int i = 0 ; i < n ; i++) {
        int parent;
        scanf("%d", &parent);
        if (parent == -1)
            continue;
        v[parent].push_back(i);
    }
    int target;
    scanf("%d", &target);
    e(target);
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        if (exist[i] == true) {
            if (v[i].size == 0)
                ans++;
            else if (v[i].size == 1 && exist[v[i][0]] == false)
                ans++;
        }
    }
    printf("%d", ans);


















  return 0;
}
