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
    vector<long long> a;
    int main() {
        int n;
        scanf("%d", &n);
        a.resize(n);
        for (int i = 0 ; i < n ;i++) {
            scanf("%lld", &a[i]);
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        int ans = 0;
        long long rans = a[n-1];
        int cnt = 0;
        for (int i = 0; i < n-1; i ++) {
            if (a[i] == a[i+1]) {
                cnt++;
                if (cnt >= ans) {
                    ans = cnt;
                    rans = a[i];
                }
            }
            else {
                cnt = 0;
            }
        }
        printf("%lld", rans);


















      return 0;
    }
