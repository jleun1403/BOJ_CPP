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
int testcase;
int n;
int main() {
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d", &n);
        int maxnum = -1;
        string maxstring;
        for (int i = 0 ; i < n ;i++) {
            string s; int al;
            cin >> s >> al;
            if (al > maxnum) {
                maxnum = al;
                maxstring = s;
            }
        }
        cout << maxstring << '\n';
    }
















  return 0;
}
