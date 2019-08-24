#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>

using namespace std;

int main() {
    int a[100001];
    int n, k;
    scanf("%d %d",&n, &k);
    if (k <= n) {
        cout << (n - k);
        return 0;
    }
    bitset<100001> b1;
    b1.set(n);
    bitset<100001> b2;
    b2.set(k);
    bitset<100001> b3(0);
    bitset<100001> b4;
    int cnt = 0;
    while((b1 & b2) == b3) {
        b4 = b1;
        for (int i = 0 ; i <= 100000 ; i++) {
            if (b4[i] == 1) {
                if (i > 0)
                    b1.set(i-1);
                if (i < 100000)
                    b1.set(i+1);
                if ( i <= 50000)
                    b1.set(2*i);
            }
        }
        cnt++;
    }
    cout <<cnt;






  return 0;
}
