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

vector<int> a = {1,2,3,4,5,6,7,8};
vector<int> d = {8,7,6,5,4,3,2,1};

int main() {
    vector<int>v;
    for (int i = 0 ; i < 8 ; i++) {
        int k;
        scanf("%d", &k);
        v.push_back(k);
    }
    if (v == a)
        printf("ascending");
    else if (v == d)
        printf("descending");
    else
        printf("mixed");
















  return 0;
}
