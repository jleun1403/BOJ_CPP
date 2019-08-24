#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main() {
    int n, task;
    vector<int> v;
    scanf("%d", &n);
    scanf("%d", &task);
    for (int i = 1 ; i <= n ; i++) {
        v.push_back(i);
    }
    if (task == 1) {
        int to;
        scanf("%d", &to);
        int cnt = 1;
        do {
            if (cnt == to)
                break;
            cnt++;
        }
        while (next_permutation(v.begin(), v.end()));
        for (int i = 0 ; i < n ; i++) {
            printf("%d ", v[i]);
        }
    }
    else {
        vector<int> p;
        int cnt = 1;
        for (int i = 0 ; i < n ; i++) {
            int k;
            cin >>k;
            p.push_back(k);
        }
        do {
            if (v == p)
                break;
            cnt++;
        }
        while (next_permutation(v.begin(), v.end()));
        printf("%d", cnt);

    }








  return 0;
}
