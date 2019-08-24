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
int dd[101][101];

int main() {
    int n;
    scanf("%d", &n);
    int a, b, c, d;
    for (int i = 0 ; i < n; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for (int k = a ; k < a+c; k++) {
            for (int l = b ; l < b+d; l++) {
                dd[k][l] = (i+1);
            }
        }
    }
    for (int k = 1; k <= n ; k++) {
    int ans = 0;
    for (int i = 0 ; i <= 100 ; i++) {
        for (int j = 0 ; j <= 100 ; j++) {
            if (dd[i][j] == k)
                ans++;
        }
    }
    printf("%d\n", ans);
    }















  return 0;
}
