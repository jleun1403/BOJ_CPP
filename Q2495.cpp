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
    for (int i = 0 ; i < 3 ; i++){
        string s;
        cin >> s;
        int maxn = 0;
        int c = 0;
        for (int j = 1 ; j < 8 ; j++) {
            if (s[j-1] == s[j]) {
                c++;
                maxn = max(maxn, c);
            }
            else
                c = 0;
        }
        printf("%d\n", maxn+1);

    }
















  return 0;
}
