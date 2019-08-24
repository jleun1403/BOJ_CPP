#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
int w[10][10];


int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            scanf("%d", &w[i][j]);
        }
        v.push_back(i);
    }
    int ans = 1000000000;
    int sum = 0;
    do {
        sum = 0;
        for (int i = 1 ; i < n ; i++) {
            if (w[v[i-1]][v[i]] == 0) {
                sum = 1000000000;
                break;
            }
            else
                sum = sum + w[v[i-1]][v[i]];
        }
        if (w[v[n-1]][v[0]] == 0)
            sum = 1000000000;
        else
            sum = sum + w[v[n-1]][v[0]];
        if (ans > sum)
            ans = sum;
    } while (next_permutation(v.begin(), v.end()));

    cout << ans;







  return 0;
}
