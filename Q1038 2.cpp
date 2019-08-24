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
int pascal[11][11];

void go() {
    pascal[1][0] = pascal[1][1] = 1;
    for (int i = 2 ; i <= 10 ; i++) {
        pascal[i][0] = pascal[i][i] = 1;
        for (int j = 1 ; j < i ; j++) {
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }
}

int main() {
    go();
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("0");
        return 0;
    }
    if (n > 1022) {
        printf("-1");
        return 0;
    }
    int on = 0;
    n += 1;
    while(true) {
        n -= pascal[10][on];
        if (n < 0)
            break;
        on++;
    }
    n += pascal[10][on];
    vector<int> v;
    for (int i = 0 ; i < 10 - on ; i++) {
        v.push_back(0);
    }
    for (int i = 0 ; i < on ; i++) {
        v.push_back(1);
    }
    while(n > 0 && next_permutation(v.begin(), v.end())) {
        n--;
    }

    for (int i = 0 ; i < 10 ; i++) {
        if (v[i] == 1) {
            printf("%d", 9-i);
        }
    }

















  return 0;
}
