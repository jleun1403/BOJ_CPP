#include <bits/stdc++.h>

using namespace std;

int divide[1000000];
long long sum[100000];

int main() {
	int testcase;
	cin >> testcase;
	while(testcase--) {
		int d, n;
		cin >> d >> n;
		memset(divide, 0, sizeof(divide));
		divide[0] = 1;
		for (int i = 1 ; i <= n ; i++) {
			long long a;
			cin >> a;
			sum[i] = sum[i-1] + a;
			divide[sum[i] % d] += 1;
		}
		long long answer = 0;
		for (int i = 0 ; i < d ; i++) {
			answer += (long long)divide[i] * (divide[i] -1) / 2;
		}
		cout << answer << '\n';
	}
	return 0;
}