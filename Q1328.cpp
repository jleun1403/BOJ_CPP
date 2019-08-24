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
#define mod 1000000007

using namespace std;
long long d[101][101][101];
int n, l, r;
long long go(int a, int b, int c){
    if (b == 0 || c == 0 || b > a || c > a) return 0;
    if (a == 1) return 1;
    if (d[a][b][c] != -1)
        return d[a][b][c];
    d[a][b][c] = ((go(a-1, b-1, c) % mod) + ((go(a-1, b, c)%mod * (a-2)) % mod) + (go(a-1, b, c-1) %mod)) %mod ;
    return d[a][b][c];



}


int main() {
    scanf("%d %d %d", &n, &l, &r);
    memset(d, -1, sizeof(d));
    printf("%lld", go(n, l, r));








  return 0;
}
