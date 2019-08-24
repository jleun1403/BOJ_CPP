#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> v;
	for (int i = 0 ; i <n ; i++) {
		int a, b;
		cin >> a>> b;
		if (a > b)
			swap(a, b);
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	vector<pair<int, int>> t(3);
	t[0] = {1, 3};
	t[1] = {1, 4};
	t[2] = {3, 4};
	if (v == t) {
		printf("Wa-pa-pa-pa-pa-pa-pow!");
	}
	else printf("Woof-meow-tweet-squeek");
	return 0;
}