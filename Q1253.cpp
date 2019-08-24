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
int a[2000];

int main() {
    int n;
    vector<int> N;
    map<int ,int> many;
    vector<int> sums;
    scanf("%d", &n);
    int zero = 0;
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 0)
            zero++;
        else
            N.push_back(a[i]);
        many[a[i]]++;
    }


    int s = N.size();
    for (int i = 0 ; i < s-1 ; i++) {
        for (int j = i+1 ; j < s ; j++) {
            sums.push_back(N[i] + N[j]);
        }
    }
    sort(sums.begin(), sums.end());

    int ret = 0;
    for (int i = 0 ; i < s ; i++) {
        if (binary_search(sums.begin(), sums.end(), N[i])) {
            ret += many[N[i]];
            many[N[i]] = 0;
        }
    }
    if (zero == 1 || zero == 2) {
        for (int i = 0 ; i < s ; i++) {
            if (many[N[i]] > 1) {
                ret += many[N[i]];
                many[N[i]] = 0;
            }
        }
        if (binary_search(sums.begin(), sums.end(), 0))
            ret += zero;
    }
    else if (zero > 2) {
        for (int i = 0 ; i < s ; i++) {
            if (many[N[i]] > 1) {
                ret += many[N[i]];
                many[N[i]] = 0;
            }
        }
        ret += zero;
    }
    printf("%d", ret);

















  return 0;
}
