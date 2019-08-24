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
int n;
int a[20][20];
int ori[20][20];

int get() {
    int sum = 0;
    for (int i = 0 ; i < n ;i++) {
        for (int j = 0 ; j < n ;j++) {
            sum += a[i][j];
        }
    }
    return sum;
}

int row(int i) {
    int sum = 0;
    for (int k = 0 ; k < n;  k++) {
        sum += a[i][k];
    }
    return sum;
}

int col(int i) {
    int sum = 0;
    for (int k = 0 ; k < n ; k++) {
        sum += a[k][i];
    }
    return sum;
}

void swap_row(int i) {
    for (int j = 0 ; j < n ; j++) {
        a[i][j] ^= 1;
    }
}

void swap_col(int j) {
    for (int i = 0 ; i < n ; i++) {
        a[i][j] ^= 1;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            char c;
            scanf(" %c",&c);
            if (c == 'T') {
                ori[i][j] = 1;
                a[i][j] = 1;
            }
        }
    }
    int ans = inf;
    for (int i = 0 ; i < (1<<n) ; i++) {
        for (int s = 0 ; s < n ; s++) {
            if ((1<<s)&i) {
                swap_row(s);
            }
        }
        for (int j = 0 ; j < n ; j++) {
            if (col(j) > n/2) {
                swap_col(j);
            }
        }
        ans = min(ans, get());
        for (int k = 0 ; k < n ; k++) {
            for (int l = 0 ; l < n ; l++) {
                a[k][l] = ori[k][l];
            }
        }
    }
    printf("%d", ans);
















  return 0;
}
