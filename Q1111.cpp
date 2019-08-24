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
vector<int>v;

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; i++) {
        int k;
        scanf("%d", &k);
        v.push_back(k);
    }
    if (n == 1)  {
        printf("A");
        return 0;
    }
    else if ( n == 2) {
        if (v[0] == v[1]) {
            printf("%d", v[0]);
            return 0;
        }
        else {
            printf("A");
            return 0;
        }
    }
    double a, b;
    int x = v[0];
    int y = v[1];
    int z = v[2];
    if ( x == y ) {
        if (y == z) {
            a = 0;
            b = x;
        }
        else {
            printf("B");
            return 0;
        }
    }
    else {
        a = (double)(z-y)/(y-x);
        b = (double)(y*y - z*x) / (y - x);
        if ((int)a != a || (int)b != b) {
            printf("B");
            return 0;
        }
    }
    for (int i = 3; i < n; i++) {
        if (v[i-1]*a + b != v[i]) {
            printf("B");
            return 0;
        }
    }
    printf("%d", (int)(v[n-1]*a + b));














  return 0;
}
