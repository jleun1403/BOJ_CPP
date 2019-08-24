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
    int n;
    ios_base::sync_with_stdio(false);
    cin >> n;
    string s;
    cin >> s;
    long long sum = 0;
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        if ( 48 <= s[i] && s[i] <= 57) {
            ans = ans*10 + (s[i]-48);
        }
        else {
            sum += (long long)ans;
            ans = 0;
        }
    }
    sum += ans;
    cout <<sum;

















  return 0;
}
