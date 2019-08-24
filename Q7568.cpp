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
class person{
public:
    int height;
    int weight;
    int order;
    person(int x, int y, int o) {
        height = x;
        weight = y;
        order = o;
    }
    bool operator<(const person &other) {
        if (height > other.height && weight > other.weight)
            return true;
        return false;
    }
};
int main() {
    int n;
    scanf("%d", &n);
    vector<person> v;
    vector<person> p;
    for (int i = 0 ; i < n ; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        person temp(x, y, 1);
        v.push_back(temp);
    }
    for (int i = 0 ; i < n ; i++) {
        int bigger = 1;
        for (int j = 0; j < n ; j++) {
            if (v[j].weight > v[i].weight && v[j].height > v[i].height)
                bigger++;
        }
        v[i].order = bigger;
    }
    for (int i = 0 ; i < n ; i++)
        printf("%d\n", v[i].order);

















  return 0;
}
