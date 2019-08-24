#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>
#define inf 987654321

using namespace std;

vector<int> v;
vector<int> ans;
int d[1000001];
int pre[1000001];

void go(int x) {
    if (x > 780000)
        return;
    v.push_back(x);
    go(10*x+4);
    go(10*x+7);
}

void print(int x) {
    if (pre[x] == x) {
        ans.push_back(x);
        return;
    }
    else {
        print(x - pre[x]);
        print(pre[x]);
    }
}

int main() {
    go(0);
    sort(v.begin(), v.end());
    fill(d, d+1000001, inf);
    memset(pre, -1, sizeof(pre));

    for (int i = 0 ; i < v.size(); i++) {
        d[v[i]] = 0;
        pre[v[i]] = v[i];
    }
    for (int i = 1 ; i <=1000000; i++) {
        for (int j = 1 ; j < v.size() ; j++) {
            if (i > v[j]) {
                if (d[i] > d[i - v[j]] + 1) {
                    d[i] = d[i - v[j]] + 1;
                    pre[i] = v[j];
                }
            }
        }
    }
    int target;
    scanf("%d", &target);
    if (d[target] == inf) {
        printf("-1");
        return 0;
    }
    else {
        print(target);
        sort(ans.begin(), ans.end());
        for (int i = 0 ; i < ans.size() ; i++)
            printf("%d ", ans[i]);
    }















  return 0;
}
