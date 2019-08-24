#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

int main() {
    int k;
    scanf("%d", &k);
    vector<int> v;
    vector<int> choose;
    while (k != 0) {
        for (int i = 0 ; i < k ;i++) {
            int p;
            cin >>p;
            v.push_back(p);
        }
        for (int i = 0 ; i < 6 ; i++)
            choose.push_back(0);
        for (int i = 0 ; i < k-6 ; i++)
            choose.push_back(1);

        do {
            for (int i = 0 ; i < k ; i++) {
                if (choose[i] == 0)
                    printf("%d ", v[i]);
            }
            printf("\n");
        } while(next_permutation(choose.begin(), choose.end()));
        printf("\n");
        v.clear();
        choose.clear();
        scanf("%d", &k);
    }








  return 0;
}
