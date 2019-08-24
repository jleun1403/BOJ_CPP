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
int a[2001];
int pal[2001][2001];
int solve(int st, int end){
    if ( end < st ) return 1;

    if (pal[st][end] != -1) return pal[st][end];

    if ( st == end ) return pal[st][end] = 1;

    if( a[st] != a[end] ) return pal[st][end] = 0;

    return pal[st][end] = solve(st+1, end-1);

}



int main() {
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++)
            pal[i][j] = -1;
    }
    int testcase;
    cin >> testcase;
    while(testcase--) {
        int start, to;
        scanf("%d %d", &start, &to);
        printf("%d\n", solve(start,to));
    }







  return 0;
}
