#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

struct brick {
    int index;
    int area;
    int height;
    int weight;
};

brick v[101];
int dp[101];
int num[101];
int pre[101];

bool cmp (brick &b1, brick &b2) {
    return b1.area > b2.area;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i++){
        scanf("%d %d %d", &v[i].area, &v[i].height, &v[i].weight);
        v[i].index = i;
    }
    sort(v+1, v+n+1, cmp);
    for (int i = 1 ; i <= n ; i++) {
        int result = 0;
        for (int j = 1 ; j < i ; j++) {
            if (v[j].weight > v[i].weight) {
                if (result < dp[j] + v[i].height) {
                    result = dp[j] + v[i].height;
                    pre[i] = j;
                    num[i] = num[j] + 1;
                    dp[i] = result;
                }
            }
        }
        if (result == 0) {
            dp[i] = v[i].height;
            pre[i] = 0;
            num[i] = 1;
        }
    }
    int ans = 0;
    int ansnum = 0;
    int ansindex = 0;
    for (int i = 1 ; i <= n ; i++) {
        if (dp[i] > ans) {
            ans = dp[i];
            ansnum = num[i];
            ansindex = i;
        }
    }

    printf("%d\n", ansnum);
    for (int i = 0 ; i < ansnum ; i++) {
        printf("%d\n", v[ansindex].index);
        ansindex = pre[ansindex];
    }
















  return 0;
}
