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
int win[1001];
int n;

int main() {
    scanf("%d", &n);
    //sk win -> 1 lose -> 0
    win[1] = 0;
    win[2] = 1;
    win[3] = 0;
    for (int i = 4; i <= 1000 ; i++) {
        if (win[i-1] == 0 || win[i-3] ==0)
            win[i] = 1;
        else
            win[i] = 0;
    }
    if (win[n] == 1)
        cout <<"SK";
    else
        cout <<"CY";








  return 0;
}
