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

struct s{
    int frequency;
    int order;
    int value;
    s(int a, int b, int c) : frequency(a), order(b), value(c) {};
    bool operator <(s &o) {
        if (frequency == o.frequency){
            return order < o.order;
        }
        return frequency > o.frequency;
    }
};

int main() {
    int n, c;
    scanf("%d %d", &n, &c);
    vector<s> v;
    for (int i = 0 ; i < n ; i++) {
        int a;
        scanf("%d", &a);
        bool found = false;
        for (int j = 0 ; j < v.size() ; j++) {
            if (v[j].value == a) {
                v[j].frequency += 1;
                found = true;
                break;
            }
        }
        if (!found) {
            v.push_back(s(1, i, a));
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0 ; i < v.size() ; i++) {
        for (int j = 0 ; j < v[i].frequency ; j++) {
            printf("%d ", v[i].value);
        }
    }
















  return 0;
}
