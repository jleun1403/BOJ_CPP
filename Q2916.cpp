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
int n, k;
vector<int> v;
int gcd(int x, int y) {
    if (y == 0) return x;
    else return gcd(y, x % y);
}


int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0 ; i < n ; i++) {
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }
    if (n == 1) {
        for (int i = 0 ; i < k ; i++) {
            int task;
            scanf("%d", &task);
            if (task % v[0] == 0)
                printf("YES\n");
            else
                printf("NO\n");
        }
        return 0;
    }
    int ans = gcd(v[0], v[1]);
    for (int i = 2 ; i < n ; i++) {
        ans = gcd(ans, v[i]);
    }
    for (int i = 0 ; i < k ; i++){
        int task;
        scanf("%d", &task);
        if (task % ans == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
















  return 0;
}
