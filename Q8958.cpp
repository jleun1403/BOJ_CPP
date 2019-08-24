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

int main() {
    int testcase;
    scanf("%d", &testcase);
    while(testcase--) {
        string s;
        cin >> s;
        int n = s.length();
        int score = 0;
        int circle = 0;
        if (s[0] == 'O') {
            score = 1;
            circle = 1;
        }
        for (int i = 1 ; i <n;  i++) {
            if (s[i] == 'O') {
                circle += 1;
                score += circle;
            }
            else
                circle = 0;
        }
        printf("%d\n", score);
    }

















  return 0;
}
