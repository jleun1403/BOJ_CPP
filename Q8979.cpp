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

struct s{
    int country;
    int gold;
    int silver;
    int bronze;
    int order;
    s(int a, int b, int c, int d) :country(a), gold(b), silver(c), bronze(d) {};

};

bool cmp(s &a, s &b) {
    if (a.gold < b.gold) {
        return false;
    }
    if (a.gold > b.gold)
        return true;
    if (a.silver < b.silver)
        return false;
    if (a.silver > b.silver)
        return true;
    if (a.bronze <= b.bronze)
        return false;
    else
        return true;
}

bool operator==(s &a, s&b) {
    if (a.gold == b.gold && a.silver == b.silver && a.bronze == b.bronze)
        return true;
    return false;

}

int main() {
    vector<s> v;
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0 ; i < n ;i++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        v.push_back(s(a, b, c, d));
    }
    sort(v.begin(), v.end(), cmp);

    v[0].order = 1;
    int point = 2;
    for (int i = 1 ; i < n ; i++) {
        v[i].order = point++;
        if (v[i] == v[i-1]) {
            v[i].order = v[i-1].order;
        }
    }
    for (int i = 0 ; i < n ;i++){
        if (v[i].country == k)
            printf("%d", v[i].order);
    }
















  return 0;
}
