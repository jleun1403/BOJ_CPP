#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
int toE(int n) {
    if ( n % 15 == 0)
        return 15;
    else
        return n % 15;
}
int toS(int n) {
    if ( n % 28 == 0)
        return 28;
    else
        return n % 28;
}
int toM(int n) {
    if (n % 19 == 0)
        return 19;
    else
        return n%19;
}

int main() {
    int e, s, m;
    cin >> e >> s >> m;
    int i = 1;
    while(true) {
        if (toE(i) == e && toS(i) == s && toM(i) == m)
            break;
        i++;
    }
    cout << i;







  return 0;
}
