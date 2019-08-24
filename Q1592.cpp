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
int n, m, l;

int cnt[1001];

int main() {
    scanf("%d %d %d", &n, &m, &l);
    int bounce = 0;
    int index = 0;
    while(cnt[index] < m-1) {
        cnt[index] +=1;
        if (cnt[index] % 2) {
            index += l;
            if (index >= n)
                index -= n;
        }
        else {
            index -= l;
            if (index < 0)
                index += n;
        }
        printf("%d\n", index);
        bounce++;
    }
    printf("%d", bounce);
















  return 0;
}
