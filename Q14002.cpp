#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int a[1000];
int dp[1000];
int pre[1000];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0 ; i <n ; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0 ; i < n ; i++) {
        int ans = 0;
        for (int j = 0 ; j < i ; j++) {
            if (a[j] < a[i] && dp[j] > ans) {
                ans = dp[j];
                pre[i] = j;
            }
        }
        dp[i] = ans + 1;
    }
    int ans = 0, last;
    for (int i = 0 ; i < n ; i++) {
        if (dp[i] > ans) {
            ans = dp[i];
            last = i;
        }
    }
    printf("%d\n", ans);
    vector<int> answer;
    for (int i = 0 ; i < ans ; i++) {
        answer.push_back(last);
        last = pre[last];
    }
    for (int i = ans - 1 ; i >= 0 ; i--) {
        printf("%d ", a[answer[i]]);
    }
















  return 0;
}
