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
#define inf 987654321

using namespace std;

int main() {
    int a, b, v;
    scanf("%d %d %d", &a, &b, &v);

    if ((v-a) % (a-b) == 0)
        printf("%d", (v-a)/(a-b)+1);
    else
        printf("%d", (v-a)/(a-b)+2);
















  return 0;
}
