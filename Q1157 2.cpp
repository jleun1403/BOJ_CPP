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
int a[26];
int main() {
    string s;
    getline(cin, s);
    int slen = s.length();
    int ans = 0;
    char answer = 'A';
    for (int i = 0 ; i < slen ; i++) {
        if (s[i] >= 65 && s[i] <= 90)
            s[i] += 32;
        a[s[i] - 97] += 1;
        if (a[s[i] - 97] > ans) {
            ans = a[s[i] - 97];
            answer = s[i] - 32;
        }
    }
    int cnt = 0;
    for (int i = 0 ; i <= 25 ; i++) {
        if (a[i] == ans)
            cnt++;
    }
    if (cnt > 1) {
        printf("?");
        return 0;
    }
    else
        printf("%c", answer);

















  return 0;
}
