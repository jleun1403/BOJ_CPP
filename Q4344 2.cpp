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
vector<int> v;
int main() {
    int testcase, n;
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d", &n);
        int sum = 0;
        for (int i = 0 ; i < n ; i++) {
            int k;
            scanf("%d", &k);
            v.push_back(k);
            sum += k;
        }
        double average = (double)sum / n;
        int over = 0;
        for (int i = 0 ; i < n; i++) {
            if (v[i] > average)
                over++;
        }
        printf("%.3lf", over / (double)n * 100);
        cout << "%\n";
        v.clear();
    }

















  return 0;
}
