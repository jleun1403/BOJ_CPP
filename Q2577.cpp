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

int used[10];

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    long long ans = (long long)a * b*c;
    while(ans > 0) {
        used[ans % 10] += 1;
        ans /= 10;
    }
    for (int i = 0 ; i < 10 ; i++) {
        printf("%d\n", used[i]);
    }
















  return 0;
}
