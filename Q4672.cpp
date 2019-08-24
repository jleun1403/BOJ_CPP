#include <bits/stdc++.h>

using namespace std;
int a[26];

int main() {
	int testcase;
	cin >> testcase;
	for (int t = 1 ; t <= testcase; t++) {
		string s;
		cin >> s;
		memset(a, 0, sizeof(a));
		for (int i = 0 ; i < s.length() ; i++) {
			a[s[i] - 'a'] += 1;
		}
		int ans = 0;
		for (int i = 0 ; i < 26 ; i++) {
			ans += (a[i]+1)*a[i]/2;
		}
		printf("#%d %d\n", t, ans);
	}
	return 0;
}