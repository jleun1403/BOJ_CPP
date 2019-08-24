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
    int n;
    vector<int> v;
    while (scanf("%1d", &n) == 1) {
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0 ; i < v.size() ; i++) {
        printf("%d", v[i]);
    }

















  return 0;
}
