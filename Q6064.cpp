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
vector<long long> M, N;
int m, n;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

long long lcm(int a, int b) {
    return (long long)a * (b / gcd(a, b));
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    while(testcase--) {
        M.clear();
        N.clear();
        scanf("%d %d", &n, &m);
        int x, y;
        scanf("%d %d", &x, &y);
        long long l = lcm(m, n);
        for (long long i = x ; i <= l ; i = i+n) {
            M.push_back(i);
        }
        bool flag = false;
        for (long long i = y ;  i <= l ; i = i+m) {
            if (binary_search(M.begin(), M.end(), i)) {
                printf("%d\n", i);
                flag = true;
            }
        }
        if (!flag)
            printf("-1\n");
    }
















  return 0;
}
