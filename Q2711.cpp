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
    int testcase;
    cin >> testcase;
    while(testcase--){
        int n ;string s;
        cin >> n >> s;
        string s1 = s.substr(0, n-1);
        string s2 = s.substr(n);
        cout << s1+s2 << '\n';
    }

















  return 0;
}
