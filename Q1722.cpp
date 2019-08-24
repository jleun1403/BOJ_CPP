#include <bits/stdc++.h>

using namespace std;

long long fact[21];
int remain[21];

int main() {
    fact[0] = 1;
    for (int i = 1; i <= 20 ; i++) {
        fact[i] = fact[i-1]*(long long)i;
        //printf("%lld\n", fact[i]);
    }
    int n;
    scanf("%d", &n);
    int task;
    scanf("%d", &task);
    if (task == 1) {
        long long k;
        scanf("%lld", &k);
        for (int i = 1 ; i <= 20 ; i++) {
            remain[i] += 1;
        }
        k--;
        int digit = n-1;
        int f = n;
        while(true) {
            if (digit == -1)
                break;
            int kth = k / fact[digit];
            kth++;
            int here = 0;
            for (int i = 1 ; i <= f ; i++) {
                if (remain[i])
                    here++;
                if (here == kth) {
                    printf("%d ", i);
                    remain[i] -= 1;
                    break;
                }
            }
            k -= fact[digit] * (kth-1);
            digit--;
        }
    }
    else {
        vector<int> v(n);
        for (int i = 0 ; i < n ; i++) {
            scanf("%d", &v[i]);
        }
        long long answer = 0;
        int digit = 0;
        while(true) {
            if (digit == n+1)
                break;
            int k = v[digit];
            answer += fact[n - digit - 1] * (v[digit] - 1);
            for (int i = digit + 1 ; i <= n ; i++) {
                if (v[i] > k)
                    v[i]--;
            }
            digit++;
        }
        printf("%lld\n", answer + 1);
    }

    return 0;
}