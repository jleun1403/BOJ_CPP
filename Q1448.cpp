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
int n;
vector<int> v(1000001);
int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0 ; i < n-2 ; i++) {
        int a = v[i];
        int b = v[i+1];
        int c = v[i+2];
        if (a < b + c) {
            printf("%d", a+b+c);
            return 0;
        }
    }
    printf("-1");

















  return 0;
}
