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
#define inf 987654321

using namespace std;
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    if (m >= 45) {
        printf("%d %d", n, m-45);
        return 0;
    }
    else {
        if (n >= 1) {
            printf("%d %d", n-1, m + 15);
        }
        else {
            printf("%d %d", 23, m +15);
        }
    }











  return 0;
}
