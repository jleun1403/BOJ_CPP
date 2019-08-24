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
int score[5];
int main() {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &score[i]);
        if (score[i] < 40)
            score[i] = 40;
        sum += score[i];
    }
    printf("%d", sum / 5);

















  return 0;
}
