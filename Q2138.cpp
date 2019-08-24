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
int a[100001];
int b[100001];
int ori[100001];
int test[100001];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%1d", &a[i]);
    }
    for (int i = 0 ; i < n ; i++) {
        scanf("%1d", &b[i]);
    }
    for (int i = 0 ; i < n ; i++) {
        if (a[i] == b[i])
            ori[i] = 0;
        else
            ori[i] = 1;
    }
    if (n == 2) {
        if (ori[0] == 0 && ori[1] == 0) {
            printf("0");
        }
        else if (ori[0] == 1 && ori[1] == 1) {
            printf("1");
        }
        else{
            printf("-1");
        }
        return 0;
    }

    for (int i = 0 ; i < n ; i++) {
        test[i] = ori[i];
    }
    // do not use first switch
    int temp = 0;
    for (int i = 1 ; i < n-1 ; i++) {
        if (test[i-1] == 1) {
            test[i-1] = 0;
            test[i] = test[i]^1;
            test[i+1] = test[i+1]^1;
            temp++;
        }
    }
    if (test[n-2] == 1) {
        test[n-2] = 0;
        test[n-1] = test[n-1]^1;
        temp++;
    }
    if (test[n-1] == 1) {
        temp = inf;
    }
    // use first switch
    int temp2 = 1;
    for (int i = 0 ; i < n ; i++) {
        test[i] = ori[i];
    }
    test[0] = test[0]^1;
    test[1] = test[1]^1;
    for (int i = 1 ; i < n-1 ; i++) {
        if (test[i-1] == 1) {
            test[i-1] = 0;
            test[i] = test[i]^1;
            test[i+1] = test[i+1]^1;
            temp2++;
        }
    }
    if (test[n-2] == 1) {
        test[n-2] = 0;
        test[n-1] = test[n-1]^1;
        temp2++;
    }
    if (test[n-1] == 1) {
        temp2 = inf;
    }
    int ans = min(temp, temp2);
    if (ans == inf) {
        printf("-1");
    }
    else
        printf("%d", ans);














  return 0;
}
