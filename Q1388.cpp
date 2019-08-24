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
char a[101][101];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            scanf(" %c", &a[i][j]);
        }
    }
    int piece = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            if (a[i][j] == '-' && a[i][j-1] != '-')
                piece++;
        }
    }
    for (int j = 1 ; j <= m ; j++) {
        for (int i = 1 ; i <= n ; i++) {
            if (a[i][j] == '|' && a[i-1][j] != '|')
                piece++;
        }
    }
    printf("%d", piece);














  return 0;
}
