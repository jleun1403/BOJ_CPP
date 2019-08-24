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
int a[100][100];
long long d[100][100] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j <n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    d[0][0] = 1LL;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            int jump = a[i][j];
            if (jump != 0) {
            if (i + jump < n)
                d[i+jump][j] += d[i][j];
            if (j + jump < n)
                d[i][j+jump] += d[i][j];
            }
        }
    }
    cout << d[n-1][n-1];







  return 0;
}
