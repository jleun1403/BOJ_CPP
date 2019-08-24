#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
vector<vector<int>> height(2);

int main() {
    int n, h;
    scanf("%d %d", &n, &h);
    for (int i = 0 ; i < n ; i++) {
        int a;
        scanf("%d", &a);
        height[i%2].push_back(a);
    }

    sort(height[0].begin(), height[0].end());
    sort(height[1].begin(), height[1].end());

    pair<int, int> answer = make_pair(inf, 0);

    for (int i = 0 ; i < h ; i++) {
        auto p = height[0].begin();
        auto q = height[1].begin();
        p = upper_bound(height[0].begin(), height[0].end(), i);
        q = lower_bound(height[1].begin(), height[1].end(), h - i);
        //printf("%d\n", height[0].end() - p + height[1].end() - q);
        if (height[0].end() - p + height[1].end() - q == answer.first) {
            answer.second += 1;
        } else if (height[0].end() - p + height[1].end() - q < answer.first) {
            answer.first = height[0].end() - p + height[1].end() - q;
            answer.second = 1;
        }
    }
    printf("%d %d", answer.first, answer.second);
    return 0;

}
