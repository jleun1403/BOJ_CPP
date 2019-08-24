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

int main() {
    int n;
    vector<string> v;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    for (int i = 0 ; i < v[0].length() ; i++) {
        char c = v[0][i];
        for (int j = 1 ; j < n ; j++) {
            if (v[j][i] != c) {
                c = '?';
                break;
            }
        }
        printf("%c", c);
    }















  return 0;
}
