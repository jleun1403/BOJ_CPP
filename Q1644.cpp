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
bool prime[4000001];
vector<int> v;
int n;

void seive() {
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n ; i++) {
        if (prime[i]) {
            for (int j = i*i ; j <= n ; j += i)
                prime[j] = false;
        }
    }
    for (int i = 2 ; i <= n ; i++) {
        if (prime[i])
            v.push_back(i);
    }
    v.push_back(45000000);
}

int main() {
    scanf("%d", &n);
    seive();
    int left = 0;
    int right = 0;
    int ans = 0;
    int sum = 0;
    int vs = v.size();
    while(true) {
        if (sum < n) {
            sum += v[right++];
        }
        else if (sum > n) {
            sum -= v[left++];
        }
        else {
            ans += 1;
            sum += v[right++];
        }
        if (right > vs) {
            break;
        }
        if (left == right) {
            if (right != vs)
                sum += v[right++];
        }
    }
    cout << ans;


















  return 0;
}
