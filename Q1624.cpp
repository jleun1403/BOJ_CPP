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

struct ds {
    int num;
    int order;
    int original;
    ds() : ds(0 ,0, 0) {}
    ds(int a, int b, int c) : num(a), order(b), original(c) {}

};

bool cmp1(ds &ds1, ds &ds2) {
    return ds1.num < ds2.num;
}
bool cmp2(ds &ds1, ds &ds2) {
    return ds1.original < ds2.original;
}

ds s[1002];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i++) {
        int a;
        scanf("%d", &a);
        s[i].num = a;
        s[i].original = i;
    }
    sort(s+1, s+n+1, cmp1);
    for (int i = 1 ; i <= n ; i++) {
        s[i].order = i;
    }
    sort(s+1, s+n+1, cmp2);

    bitset<1002> answer;
    bitset<1002> temp;
    answer.reset();
    int number_of_deque = 0;
    for (int i = 1 ; i <= n ; i++) {
        if (answer[s[i].order +1] == 0 && answer[s[i].order -1] == 0) {
            number_of_deque++;
        }
        temp.set(s[i].order);
        answer = answer | temp;
    }
    printf("%d", number_of_deque);
















  return 0;
}
