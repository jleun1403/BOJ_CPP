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
int a[1831];
int sum[1831];

int main() {
    ios_base::sync_with_stdio(false);
    int k = 1;
    for (int i = 1 ; i <= 60 ; i++) {
        int t = 0;
        while(t < i) {
            a[k+t] = i;
            sum[k+t] = sum[k+t-1] + i;
            t++;
        }
        k +=t ;
    }
    int x, y;
    cin >> x >> y;
    cout << sum[y] - sum[x-1];















  return 0;
}
