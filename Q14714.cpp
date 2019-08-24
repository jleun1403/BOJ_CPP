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
#define inf 500000

using namespace std;
int A[501];
int B[501];
int da, db, n;

bitset<501> a;
bitset<501> b;
bitset<501> temp;


int main() {
    int as, bs;
    scanf("%d %d %d %d %d", &n, &as, &bs, &da, &db);
    int choose = 1;
    a.set(as); b.set(bs);
    while(choose <= 1000) {
        for (int i = 1 ; i<= n ; i++) {
            if (a[i]) {
                int next1 = i + da > n ? i + da - n : i + da;
                int next2 = i - da < 1 ? i - da + n : i - da;
                temp.set(next1);
                temp.set(next2);
            }
        }
        if ((temp & b) != 0) {
            break;

        }
        a = temp;
        temp.reset();
        choose++;
        for (int i = 1 ; i <= n ; i++) {
            if (b[i]) {
                int next1 = i + db > n ? i + db - n : i + db;
                int next2 = i - db < 1 ? i - db + n : i - db;
                temp.set(next1);
                temp.set(next2);
            }
        }
        if ((temp & a) != 0) {
            break;
        }
        b = temp;
        temp.reset();
        choose++;
    }
    if (choose == 1001)
        printf("Evil Galazy");
    else
        printf("%d", choose);















  return 0;
}
