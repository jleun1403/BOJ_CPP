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
int n, m;
int a[1000][1000];

bool isPossible(int x, int y, int k) {
    for (int i = x ; i < x + k ; i++){
        for (int j = y;  j < y + k ; j++) {
            if (a[i][j] == 0)
                return false;
        }
    }
    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            scanf("%1d", &a[i][j]);
        }
    }

    int left = 1;
    int right = 1000;
    int mid;
    int ans = 10;
    while(left+1 < right) {
        mid = (left + right) /2;
        bool flag  = false;
        for (int i = 0 ; i <= n - mid ; i++) {
            for (int j = 0 ; j <= m - mid ; j++) {
                if (a[i][j] == 0)
                    continue;
                if (isPossible(i, j, mid)) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag) {
            ans = mid;
            left = mid;
        }
        else
            right = mid;
    }
    printf("%d", ans*ans);
















  return 0;
}
