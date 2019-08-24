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

long long f(long long x) {
    long long ans = 0;
    long long a = 2;
    while(x >= a) {
        ans += x / a;
        a *= 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    long long x , y;
    cin >>x;
    cout << f(x);















  return 0;
}
