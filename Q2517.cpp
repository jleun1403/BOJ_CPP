#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int a[500001];
int n;
int tree[500050];

void update(int index, int value) {
    for (int i = index ; i <= n ; i += i&-i) {
        tree[i] += value;
    }
}

int query(int index) {
    int ans = 0;
    for (int i = index; i > 0 ; i -= i&-i) {
        ans += tree[i];
    }
    return ans;
}

struct person {
    int order;
    int original_ability;
    int new_ability;
};
vector<person> v;

bool cmp1(person &p1, person &p2) {
    return p1.original_ability < p2.original_ability;
}

bool cmp2(person &p1, person &p2) {
    return p1.order < p2.order;
}

int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        person t;
        scanf("%d", &t.original_ability);
        t.order = i;
        t.new_ability = 0;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp1);
    for (int i = 0 ; i < n ; i++) {
        v[i].new_ability = i+1;
    }
    sort(v.begin(), v.end(), cmp2);
    for (int i = 0 ; i < n ; i++) {
        int p = v[i].new_ability;
        printf("%d\n", query(n) - query(p) + 1);
        update(p, 1);
    }

















  return 0;
}
