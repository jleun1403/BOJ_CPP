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
    int n;
    scanf("%d", &n);
    int ans = n;
    int next = (n%10 *10 + (n/10 + n%10)%10);
    int cnt = 1;
    while(next != ans) {
        n = next;
        next = (n%10 *10 + (n/10 + n%10)%10);
        cnt++;
    }
    printf("%d", cnt);















  return 0;
}
