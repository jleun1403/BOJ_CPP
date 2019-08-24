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
int n, m;
vector<int> v;
int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ;i++) {
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }
    scanf("%d", &m);
    sort(v.begin(), v.end());
    for (int i = 0 ; i < m ;i++) {
        int a;
        scanf("%d", &a);
        if (binary_search(v.begin(), v.end(), a)){
            printf("1\n");
        }
        else {
            printf("0\n");
        }
    }
















  return 0;
}
