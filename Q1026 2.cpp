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
int n;
vector<int> a;
vector<int> b;
int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        int k;
        scanf("%d", &k);
        a.push_back(k);
    }
    for (int i = 0 ; i < n ; i++) {
        int k;
        scanf("%d", &k);
        b.push_back(k);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    int sum = 0;
    for (int i = 0 ; i < n ; i++) {
        sum += a[i] * b[i];
    }
    printf("%d", sum);
















  return 0;
}
