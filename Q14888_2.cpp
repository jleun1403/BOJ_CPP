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
int n;
int maxans = -inf;
int minans = inf;
int numbers[12];
int d[4];

bool canuse(int i) {
    if (d[i] > 0)
        return true;
    return false;
}

void go(int index, int made) {

    if (index == n) {
        maxans = max(maxans, made);
        minans = min(minans, made);
        return;
    }
    int ans = made;
    if (canuse(0)) {
        d[0]--;
        made = ans + numbers[index];
        go(index + 1, made);
        d[0]++;
    }
    if (canuse(1)) {
        d[1]--;
        made = ans - numbers[index];
        go(index +1, made);
        d[1]++;
    }
    if (canuse(2)) {
        d[2]--;
        made = ans * numbers[index];
        go(index +1, made);
        d[2]++;
    }
    if (canuse(3)) {
        d[3]--;
        made = ans / numbers[index];
        go(index+1, made);
        d[3]++;
    }

}

int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0 ; i <4; i++) {
        scanf("%d", &d[i]);
    }
    go(1, numbers[0]);
    printf("%d\n%d", maxans, minans);
  return 0;
}
