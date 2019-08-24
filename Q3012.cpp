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
int n;
char s[201];
long long d[201][201];
char open[5] = "({[";
char close[5] = ")}]";
bool over;


long long go(int i, int j) {
    if (i > j)
        return 1LL;
    if (d[i][j] != -1)
        return d[i][j];
    long long ans = 0;
    for (int k = i+1; k <= j ; k += 2) {
        for (int l = 0 ; l < 3 ; l++) {
            if (s[i] == open[l] || s[i] == '?') {
                if (s[k] == close[l] || s[k] == '?') {
                    long long temp = go(i+1, k-1) * go(k+1, j);
                    if (ans + temp >= 100000LL){
                        over = true;
                    }
                    ans += temp;
                    ans %= 100000LL;
                }
            }
        }
    }
    return d[i][j] = ans;
}


int main() {
    scanf("%d", &n);
    if (n % 2 == 1) {
        cout << 0;
        return 0;
    }
    cin >> s;
    over = false;
    memset(d, -1, sizeof(d));
    long long ans = go(0, n-1);
    if ((over)) {
        printf("%05lld\n", ans);
    }
    else
        printf("%lld\n", ans);






  return 0;
}
