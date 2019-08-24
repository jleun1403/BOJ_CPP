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

int main() {
    long long k;
    scanf("%lld", &k);
    k += 1;
    stack<int> s;
    while(k > 0) {
        if (k % 2) {
            s.push(7);
        }
        else {
            s.push(4);
        }
        k = k >> 1;
    }
    s.pop();
    int ss = s.size();
    for (int i = 0 ; i < ss; i++) {
        printf("%d", s.top());
        s.pop();
    }
















  return 0;
}
