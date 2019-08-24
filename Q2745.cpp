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
int mypow(int a, int b) {
    if (b == 0) return 1;
    if ( b == 1) return a;
    if (b % 2 == 0) {
        int temp = mypow(a, b/2);
        return temp *temp;
    }
    else {
        return mypow(a, b-1) * a;
    }
}

int main() {
    string s; int b;
    cin >> s >> b;
    int n = s.length();
    int sum = 0;
    for (int i = 0 ; i < n ; i++) {
        if (s[n-1-i] >= 48 && s[n-1-i] <= 57)
            s[n-1-i] = s[n-1-i] - 48;
        else
            s[n-1-i] = s[n-1-i] - 'A' + 10;
        sum += s[n-1-i]* mypow(b, i);
    }
    cout << sum;






  return 0;
}
