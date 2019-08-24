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

int main() {
    set<int> s;
    for (int i = 0 ; i < 10 ; i++) {
        int n;
        scanf("%d", &n);
        n = n % 42;
        s.insert(n);
    }
    printf("%d", s.size());

















  return 0;
}
