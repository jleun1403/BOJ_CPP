#include <bits/stdc++.h>

using namespace std;

int t;
vector<int> group;

bool cmp(int a, int b) {
	if (group[a] != group[b])
		return group[a] < group[b];
	return group[a+t] < group[b+t];
}

vector<int> getSuffixArray(const string &s) {
	int n = s.length();
	t = 1;
	group.resize(n+1);
	for (int i = 0 ; i < n ; i++)
		group[i] = s[i];
	group[n] = -1;

	vector<int> perm(n);
	for (int i = 0 ; i < n ; i++) {
		perm[i] = i;
	}
	while(t < n) {
		sort(perm.begin(), perm.end(), cmp);
		if (t*2 >= n)
			break;

		vector<int> newGroup(n+1);
		newGroup[n] = -1;
		newGroup[perm[0]] = 0;
		for (int i = 1 ; i < n ; i++) {
			if (cmp(perm[i-1], perm[i]))
				newGroup[perm[i]] = newGroup[perm[i-1]] + 1;
			else newGroup[perm[i]] = newGroup[perm[i-1]];
		}
		group = newGroup;
		t *= 2;
	}
	return perm;
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> SuffixArray = getSuffixArray(s);
	vector<int> pos(n);
	vector<int> LCP(n);
	for (int i = 0 ; i < n ; i++) {
		pos[SuffixArray[i]] = i;
	}

	for (int i = 0 , k = 0; i < n ; i++, k = max(k-1, 0)) {
		if (pos[i] == n-1)
			continue;
		for (int j = SuffixArray[pos[i] + 1]; s[i+k] == s[j+k] ; k++);
		LCP[pos[i]] = k;
	}
	int ans = 0;
	for (int i = 0 ; i < n; i++) {
		ans = max(ans, LCP[i]);
		//printf("%d %d\n", SuffixArray[i], LCP[i]);
	}
	printf("%d\n", ans);

	return 0;
}