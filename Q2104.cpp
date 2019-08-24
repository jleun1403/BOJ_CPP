#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
long long n, a[100000];

long long go(long long left, long long right) {
    if (left == right) return a[left] * a[left];
    long long mid = (left + right) / 2;
    long long ans = max(go(left, mid), go(mid+1, right));

    long long low = mid;
    long long high = mid +1;
    long long sum = a[low] +a[high];
    long long minimum = min(a[low], a[high]);
    ans = max(ans, (long long)sum * minimum);
    while(true) {
        if (low == left && high == right)
            break;
        else if (low == left) {
            high += 1;
            sum += a[high];
            minimum = min(minimum, a[high]);
            ans = max(sum * minimum, ans);
        }
        else if (high == right) {
            low -= 1;
            sum += a[low];
            minimum = min(minimum, a[low]);
            ans = max(sum * minimum, ans);
        }
        else {
            if (a[high + 1] > a[low -1]) {
                high += 1;
                sum += a[high];
                minimum = min(minimum, a[high]);
                ans = max(sum * minimum, ans);
            }
            else {
                low -= 1;
                sum += a[low];
                minimum = min(minimum, a[low]);
                ans = max(sum * minimum, ans);
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    cout << go(0, n-1);















  return 0;
}
