#include <bits/stdc++.h>
using namespace std;

vector<long long> a;
vector<long long> answer(3);
int n;
const long long inf = 100000000000000LL;

int main() {
	cin >> n;
	for (int i = 0 ; i < n ; i++) {
		long long t;
		cin >> t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	long long minimum = inf;
	for (int i = 0 ; i < n ; i++) {
		for (int j = i+1; j < n ; j++) {
			long long next = (a[i] + a[j]) * -1;
			auto p = lower_bound(a.begin(), a.end(), next);
			long long ans1, ans2;
			if (p == a.end()) {
				if (j == n - 1)
					continue;
				if (abs(a[i] + a[j] + (*(p-1))) < minimum) {
					minimum = abs(a[i] + a[j] + (*(p-1)));
					answer[0] = a[i];
					answer[1] = a[j];
					answer[2] = *(p-1);
				}
			}
			else if (p == a.begin()) {
				if (i == 0)
					continue;
				if (abs(a[i] + a[j] + (*p)) < minimum) {
					answer[0] = a[i];
					answer[1] = a[j];
					answer[2] = *p;
					minimum = abs(a[i] + a[j] + (*p));
				}
			}
			else {
				if (abs(a[i] + a[j] + (*p)) < minimum && (*p) != a[i] && (*p) != a[j]) {
					answer[0] = a[i];
					answer[1] = a[j];
					answer[2] = *p;
					minimum = abs(a[i] + a[j] + (*p));
				}
				if (abs(a[i] + a[j] + (*(p-1))) < minimum && *(p-1) != a[i] && *(p-1) != a[j]) {
					answer[0] = a[i];
					answer[1] = a[j];
					answer[2] = *(p-1);
					minimum = abs(a[i] + a[j] + (*(p-1)));
				}
			}
		}

	}
	sort(answer.begin(), answer.end());
	cout << answer[0] << ' ' << answer[1] << ' ' <<answer[2] <<'\n';
	return 0;
}