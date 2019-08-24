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
    string s1, s2;
    cin >> s1 >>s2;
    int a= 0; int b = 0;
    for (int i = 0 ; i < s1.length() ; i++) {
        a += (s1[i] - 48);
    }
    for (int i = 0 ; i < s2.length(); i++){
        b += (s2[i] - 48);
    }
    printf("%lld", (long long)a *b);
















  return 0;
}
