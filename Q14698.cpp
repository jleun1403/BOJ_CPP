#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int testcase;
int n;

int main() {
	scanf("%d", &testcase);
	while(testcase--) {
		scanf("%d", &n);
		priority_queue<long long> pq;
		for (int i = 0 ; i < n ; i++) {
			long long t;
			scanf("%lld", &t);
			pq.push(-t);
		}
		long long ans = 1LL;
		while(pq.size() > 1) {
			long long cur = 1LL;
			cur *= -pq.top() % mod;
			pq.pop();
			cur *= -pq.top();
			ans *= (cur % mod);
			ans %= mod;
			pq.pop();
			pq.push(-cur);
		}
		printf("%lld\n", ans);

	}
	return 0;
}