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
    vector<string> original;
    vector<string> compare;
    int n;
    scanf("%d", &n);
    for (int i = 0 ; i < n; i++) {
        string s;
        cin >> s;
        original.push_back(s);
        compare.push_back(s);
    }
    sort(compare.begin(), compare.end());
    if (original == compare) {
        printf("INCREASING");
        return 0;
    }
    reverse(compare.begin(), compare.end());
    if (original == compare) {
        printf("DECREASING");
        return 0;
    }
    printf("NEITHER");
















  return 0;
}
