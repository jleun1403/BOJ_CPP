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
vector<int> v;
int n;
int pos, neg;

int main() {
    scanf("%d", &n);
    pos = neg = 0;
    for (int i = 0 ; i < n ; i++) {
        int k;
        scanf("%d", &k);
        if ( k > 0)
            pos++;
        if (k < 0)
            neg++;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    if (neg == 0) {
        printf("%d %d", v[0], v[1]);
        return 0;
    }
    if (pos == 0) {
        printf("%d %d", v[n-2], v[n-1]);
        return 0;
    }

    int ans = 1000000001;
    int a[2];
    int start = 0, fin = n-1;
    while(start < fin) {
        if (abs(v[start] + v[fin]) < ans) {
            ans = abs(v[start] +v[fin]);
            a[0] = v[start];
            a[1] = v[fin];
        }
        if (v[start] + v[fin] > 0) {
            fin--;
        }
        else
            start++;
    }
    printf("%d %d", a[0], a[1]);








  return 0;
}
