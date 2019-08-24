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
vector<int> a;
vector<int> b;


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i < m + n ; i++) {
        int k;
        scanf("%d", &k);
        a.push_back(k);
    }
    sort(a.begin(), a.end());
    for (int i = 0 ; i < m+n; i++) {
        printf("%d ", a[i]);
    }
















  return 0;
}
