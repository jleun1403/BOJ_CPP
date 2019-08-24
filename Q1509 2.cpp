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
int pal[2500][2500];
int d[2501];


int main() {
    string s;
    cin >> s;
    int n = s.length();

    for (int i = 0 ; i < n ; i++)
        pal[i][i] = 1;
    for (int i = 0 ; i < n - 1 ; i++) {
        pal[i][i+1] = (s[i] == s[i+1]);
    }

    for (int k = 3 ; k <= n ; k++){
        for (int i = 0 ; i <= n - k ; i++) {
            int j = i + k - 1;
            if (s[i] == s[j] && pal[i+1][j-1])
                pal[i][j] = 1;
        }
    }
    d[0] = 1;
    if (pal[0][1])
        d[1] = 1;
    else
        d[1] = 2;
    for (int i = 1; i < n ; i++) {
        int p = n;
        for (int j = 0 ; j <= i; j++) {
            if (pal[j][i] == 1 && d[j-1] < p) {
                d[i] = d[j-1] + 1;
                p = d[j-1];
            }
        }
    }
    cout << d[n-1];








  return 0;
}
