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
    vector<int> v= {0, 0, 1, 1, 1, 1, 1, 1, 1};
    int a[9];
    for (int i = 0 ; i < 9 ; i++)
        scanf("%d", &a[i]);
    do {
        int sum = 0;
        for (int i = 0 ; i < 9 ; i++) {
            if (v[i] == 1)
                sum += a[i];
        }
        if (sum == 100) {
            for (int i = 0 ; i < 9 ; i++) {
                if (v[i] == 1) {
                    printf("%d\n", a[i]);
                }
            }
            return 0;
        }
    }while(next_permutation(v.begin(), v.end()));







  return 0;
}
