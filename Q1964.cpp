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

int ans[10000001];

int main() {
    int n;
    scanf("%d", &n);
    ans[1] = 5;
    for (int i = 2; i <= 10000000 ; i++) {
        ans[i] = (ans[i-1] + 3*i + 1 ) % 45678;
    }
    printf("%d", ans[n]);















  return 0;
}
