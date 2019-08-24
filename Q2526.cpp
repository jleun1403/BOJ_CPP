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
#define inf 987654321

using namespace std;
int n, p;
int rec[1001];

int main() {
    scanf("%d %d", &n, &p);
    rec[n] += 1;
    int k = n;
    for (int i = 0 ; i < 1000000; i++) {
        int next = (k*n) % p;
        rec[next] += 1;
        k = next;
    }
    int ans = 0;
    for (int i = 0 ; i < 1001 ; i++) {
        if (rec[i] > 1) {
            ans++;
        }
    }
    printf("%d", ans);















  return 0;
}
