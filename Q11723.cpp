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
char s[200];
int main() {
    int n;
    scanf("%d", &n);
    int k = 0;
    while(n--) {
        scanf("%s", &s);
        if (!strcmp(s, "add")) {
            int x;
            scanf("%d", &x);
            k = (k | (1<<x));
        }
        else if (!strcmp(s, "remove")) {
            int x;
            scanf("%d", &x);
            k = k&(~(1<<x));
        }
        else if (!strcmp(s, "check")) {
            int x;
            scanf("%d", &x);
            printf("%d\n", (k&(1<<x)) != 0);
        }
        else if (strcmp(s, "toggle")) {
            int x;
            scanf("%d", &x);
            k = k ^ (1<<x);
        }
        else if (strcmp(s, "all")) {
            k = (1<<22) -1;
        }
        else if (strcmp(s, "empty")) {
            k = 0;
        }
    }

















  return 0;
}
