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
int n;
vector<int> v;

int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        int k;
        scanf("%d", &k);
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    printf("%d", v[0] *v[n-1]);
















  return 0;
}
