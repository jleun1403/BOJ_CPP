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

bool palindrome(string s) {
    int n = s.length();
    if (n == 0)
        return true;
    else if (n == 1)
        return true;
    if (s[0] != s[n-1])
        return false;
    return palindrome(s.substr(1, n-2));
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    while(testcase--) {
        string c;
        cin >> c;
        string c2 = c;
        reverse(c.begin(), c.end());
        int a = stoi(c2) + stoi(c);
        if (palindrome(to_string(a))) {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
















  return 0;
}
