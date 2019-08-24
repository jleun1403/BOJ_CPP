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
    while(testcase--){
        char a, b, c;
        scanf(" %1c", &a);
        scanf(" %1c", &b);
        scanf(" %1c", &c);
        printf("%d\n", a-'0' + c -'0');
    }

















  return 0;
}
