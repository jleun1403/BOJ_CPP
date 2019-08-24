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
int n, s, m;

int main() {
    bitset<1050> b;
    bitset<1050> temp;
    scanf("%d %d %d", &n, &s, &m);
    b.set(s);
    while(n--){
        int v;
        scanf("%d", &v);
        for (int i = 0 ; i <= m ; i++) {
            if (b[i] == 1) {
                if (((i + v > m) || (i+v <= m && b[i+v] == 0)) && ((i - v < 0) || (i-v >=0 && b[i-v] == 0))) {
                    temp.set(i, false);
                }
                if (i + v <= m) {
                    temp.set(i+v);
                }
                if (i - v >= 0)
                    temp.set(i-v);
            }
        }
        b = temp;
    }
    for (int i = m ; i >= 0 ; i--){
        if (b[i] == 1){
            cout << i;
            return 0;
        }
    }
    cout << -1;







  return 0;
}
