#include <bits/stdc++.h>

using namespace std;
int a[100000];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0 ;i < n ; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	int ans = -1;
	for (int mid = 1 ; mid < n-1 ; mid++) {
		int left = 0;
		int right = mid+1;
		ans = max(ans, abs(a[left] - 2*a[mid] + a[right]));
	}
	int right = n-1;
	for (int left = 0 ; left < n - 2; left++) {
		int mid = left + 1;
		ans = max(ans, abs(a[left] - 2*a[mid] + a[right]));
	}
	printf("%d\n", ans);

	return 0;
}