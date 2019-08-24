#include <bits/stdc++.h>

using namespace std;
string t[101];
int strike[101];
int ball[101];
int cmp[10];

pair<int, int> comp(string &s1, string &s2) {
	memset(cmp, 0, sizeof(cmp));
	pair<int, int> ret = make_pair(0, 0);
	for (int i = 0 ; i < 3 ; i++) {
		cmp[s1[i] - '0']++;
		cmp[s2[i] - '0']++;
	}
	for (int i = 0 ; i < 3 ; i++) {
		if (s1[i] == s2[i]) {
			ret.first++;
			cmp[s1[i] - '0'] -= 2;
		}
	}
	for (int j = 0 ; j < 10 ; j++) {
		if (cmp[j] == 2)
			ret.second++;
	}
	return ret;
}

int main() {
	int test;
	cin >> test;
	for (int i = 0 ; i < test ; i++) {
		cin >> t[i] >> strike[i] >> ball[i];
	}
	int ans = 0;
	for (int i = 123; i <= 987 ; i++) {
		string target = to_string(i);
		memset(cmp, 0, sizeof(cmp));
		for (int i = 0 ; i < 3;  i++) {
			cmp[target[i] - '0']++;
		}
		bool over = false;
		for (int j = 0 ; j < 10 ; j++) {
			if (cmp[j] > 1)
				over = true;
		}
		if (over || cmp[0])
			continue;
		int temp = 0;
		for (int j = 0 ; j < test ; j++) {
			auto p = comp(target, t[j]);
			if (p.first == strike[j] && p.second == ball[j])
				temp++;
		}
		if (temp == test)
			ans++;
	}
	printf("%d\n", ans);

	return 0;
}