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
int n, m;
vector<int> v;
int main() {
    scanf("%d", &n);
    scanf("%d", &m);
    v.push_back(0);
    for (int i = 0 ; i < m ; i++) {
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }
    v.push_back(n+1);
    int ans = 1;
    for (int i = 0 ; i < m+1; i++) {
        int dist = v[i+1] - v[i] -1;
        if (dist >=2) {
            ans *= (dist);
        }
    }
    printf("%d", ans);
















  return 0;
}
