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

int main() {
    int testcase;
    scanf("%d", &testcase);
    while(testcase--) {
        int hp, mp, ad, ar, t1, t2, t3, t4;
        scanf("%d %d %d %d %d %d %d %d", &hp, &mp, &ad, &ar, &t1, &t2, &t3, &t4);
        if (hp + t1 < 1)
            hp = 1;
        else
            hp = hp +t1;
        if (mp + t2 < 1)
            mp = 1;
        else
            mp = mp + t2;
        if (ad + t3 < 0)
            ad = 0;
        else
            ad = ad + t3;
        ar = ar + t4;
        int abi = hp + 5*mp + 2*ad + 2*ar;
        cout << abi << '\n';

    }








  return 0;
}
