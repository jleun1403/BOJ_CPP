#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>

using namespace std;
int n, mnum;
vector<int> m;
long long until(long long t) {
    long long p = mnum;
    for (int i = 0 ; i < mnum ; i++) {
        p = p + (t / m[i]);
    }
    return p;
}

int main() {
    int pause;
    scanf("%d %d", &n, &mnum);
    m.resize(mnum);
    for (int i = 0 ; i < mnum ; i++)
        scanf("%d", &m[i]);
    if (n <= mnum) {
        cout << n ;
        return 0;
    }
    long long left = 1;
    long long right = 6000000000000000LL;
    int ans = 0;
    while (left <= right) {
        long long mid = (left +right ) >> 1;

        if (until(mid - 1) < n && n <= until(mid))
            {
            int temp = n - until(mid - 1);
            for (int i = 0 ; i < mnum ; i++) {
                if (mid % m[i] == 0)
                    temp--;
                if (temp == 0) {
                    ans = i + 1;
                    break;
                }
            }
            break;
        }
        if (until(mid) >= n) {
            right = mid - 1;
        }
        else if (until(mid) < n) {
            left = mid + 1;
        }
    }
    cout <<ans;







  return 0;
}
