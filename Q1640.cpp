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
int ori[1000][1000];

int row(int i) {
    int sum = 0;
    for (int j = 0 ; j < m ; j++) {
        sum += a[i][j];
    }
    return sum;
}

int col(int i) {
    int sum = 0;
    for (int j = 0 ; j < n ; j++) {
        sum += a[j][i];
    }
    return sum;
}

void swap_row(int i) {
    for (int j = 0 ; j < m ; j++) {
        a[i][j] ^= 1;
    }
}

int main() {
    scanf("%d %d", &n,&m);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            scanf("%1d", &a[i][j]);
            ori[i][j] = a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        if (row(i) % 2 == 0) {
            swap_row(i);
            ans++;
        }
    }
    int anscol = 0;
    for (int j = 0 ; j < m ; j++) {
        if (col(j) % 2) {
            anscol++;
        }
    }
    int ans1 = ans +anscol;
    if (anscol % 2 == 0)
        ans1 = inf;

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            a[i][j] = ori[i][j];
        }
    }

    int aaa = 0;
    for (int i = 0 ; i < n ; i++) {
        if (row(i) % 2) {
            aaa++;
            swap_row(i);
        }
    }
    int anscol2 = 0;
    for (int j = 0 ; j < m ; j++) {
        if (col(j) % 2) {
            anscol2++;
        }
    }
    int ans2 = aaa + anscol2;
    if (anscol2 % 2)
        ans2 = inf;
    int final_answer = min(ans1, ans2);
    if (final_answer == inf) {
        printf("-1");
    }
    else{
        printf("%d", final_answer);
    }














  return 0;
}
