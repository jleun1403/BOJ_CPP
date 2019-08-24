#include <bits/stdc++.h>

using namespace std;

long long a[1000];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0 ; i < n ; i++) {
		cin >> a[i];
	}
	for (int i = 0 ; i < m ; i++) {
		long long min1 = (1LL<<62);
		long long min2 = (1LL<<62);
		int min1_index = 0, min2_index = 0;
		for (int j = 0 ; j < n ; j++) {
			if (a[j] >= min1)
				continue;
			else if (min2 <= a[j] && a[j] < min1) {
				min1 = a[j];
				min1_index = j;
			}
			else if (a[j] < min2) {
				min1 = min2;
				min1_index = min2_index;
				min2 = a[j];
				min2_index = j;
			}
		}
		a[min1_index] = a[min2_index] = min1 + min2;
	}
	long long answer = 0;
	for (int i = 0 ; i < n ; i++) {
		answer += a[i];
	}
	printf("%lld\n", answer);
	return 0;
}