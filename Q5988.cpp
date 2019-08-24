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

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        int t = s.length();
        int a = s[t-1] - '0';
        if (a % 2) {
            cout << "odd" << '\n';
        }
        else {
            cout << "even" << '\n';
        }
    }
















  return 0;
}
