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

double d[5][5][5][5][5][5][5][5][5];
char s[9][5][3];

double go(vector<int> l) {
    if ((l[0]+l[1]+l[2]+l[3]+l[4]+l[5]+l[6]+l[7]+l[8]) == 0)
        return 1.0;
    if (d[l[0]][l[1]][l[2]][l[3]][l[4]][l[5]][l[6]][l[7]][l[8]] >= 0)
        return d[l[0]][l[1]][l[2]][l[3]][l[4]][l[5]][l[6]][l[7]][l[8]];
    int cnt = 0;
    for (int i = 0 ; i < 8 ; i++) {
        for (int j = i+1 ; j < 9 ; j++) {
            if (l[i] != 0 && l[j] != 0) {
                if (s[i][l[i]][0] == s[j][l[j]][0]) {
                    cnt++;
                }
            }
        }
    }
    if (cnt == 0 )
        return d[l[0]][l[1]][l[2]][l[3]][l[4]][l[5]][l[6]][l[7]][l[8]]=0.0;
    double p = 1.0/cnt;
    double ans = 0.0;
    for (int i = 0 ; i < 8 ; i++) {
        for (int j = i+1 ; j < 9 ; j++) {
            if (i == j)
                continue;
            if (l[i] != 0 && l[j] != 0) {
                if (s[i][l[i]][0] == s[j][l[j]][0]) {
                    l[i]--;
                    l[j]--;
                    ans += go(l);
                    l[i]++;
                    l[j]++;
                }
            }
        }
    }
    return d[l[0]][l[1]][l[2]][l[3]][l[4]][l[5]][l[6]][l[7]][l[8]] = ans *p;
}

int main() {
    ios_base::sync_with_stdio(false);
    for (int i = 0 ; i < 9 ; i++) {
        for (int j = 1 ; j <= 4 ; j++) {
            scanf("%s", s[i][j]);
        }
    }
    vector<int> l(9, 4);
    memset(d, -1, sizeof(d));
    go(l);
    printf("%lf", d[4][4][4][4][4][4][4][4][4]);















  return 0;
}
