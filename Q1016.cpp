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
long long mi, ma;
int a[1000001];

int main() {
    scanf("%lld %lld", &mi, &ma);
    for (long long i = 2LL ; i * i <= ma ; i++) {
        long long x = mi / (i*i);
        if (mi % (i*i) != 0)
            x++;

        while(x *(i*i)<= ma) {

            a[x*i*i - mi] = 1;
            x++;
        }

    }
    int cnt = 0;
    for (int i = 0 ; i <= ma - mi ; i++) {
        if (a[i] == 0)
            cnt++;
    }
    printf("%d", cnt);








  return 0;
}
