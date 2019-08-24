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
int c;
long long mypow(long long a, long long b) {
    if (b == 0) return 1;
    if (b == 1) return a % c;
    if (b % 2 == 0) {
        long long temp = mypow(a, b/2);
        return temp *temp % c;
    }
    else return (a * mypow(a, b-1)) % c;
}

int main() {
    int a, b;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d", mypow(a,b) % c);







  return 0;
}
