#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>

using namespace std;
int possible[10] = {1,1,1,1,1,1,1,1,1,1};
int direct(int n){
    int c = n;
    int i = 0;
    if (c == 0) {
        return possible[0];
    }
    while(c > 0) {
        int p = c % 10;
        if (possible[p] == 0)
            return 0;
        c = c / 10;
        i++;
    }
    return i;
}


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++) {
        int k;
        cin >> k;
        possible[k] = 0;
    }
    if (98 <= n && n <= 102) {
        cout << abs(n - 100);
        return 0;
    }
    int ans = 500000 - 100;
    int minimum;
    for (int i = 0 ; i < 1000000 ; i++) {
        int click = direct(i);
        if (click == 0) {
            minimum = abs(n - 100);
        }
        else {
            minimum = click + abs(i - n);
        }
        if (ans > minimum)
            ans = minimum;
    }
    cout << ans;







  return 0;
}
