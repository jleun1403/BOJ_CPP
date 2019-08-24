#include <bits/stdc++.h>

using namespace std;
int a[15][15];
vector<vector<int>> v(15);

int bit_count(int x) {
	int ret = 0;
	for (int i = 0 ; i < 25 ; i++) {
		if (x & (1<<i))
			ret++;
	}
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n; j++) {
			scanf("%1d", &a[i][j]);
			if (a[i][j]) {
				v[i].push_back(j);
			}
		}
	}
	if (n == 1 && a[0][0] == 1) {
		printf("1");
		return 0;
	} 
	if (n == 2) {
		printf("2");
		return 0;
	}
	int ans = 0;
	for (int i = 1 ; i < (1<<n) ; i++) {
		vector<int> leaf;
		vector<int> middle;
		bool can_make = true;
		bool check[16];
		memset(check, false, sizeof(check));
		for (int j = 0 ; j < n ; j++) {
			if (i & (1<<j)) {
				leaf.push_back(j);
			}
			else middle.push_back(j);
		}
		for (int j = 0 ; j < middle.size() ; j++) {
			for (int k = 0 ; k < v[middle[j]].size() ; k++){
				check[v[middle[j]][k]] = true;
			}
		}
		int center = 20;
		if (middle.size() == 1) {
			center = middle[0];
		}
		for (int j = 0 ; j < n ; j++) {
			if (!check[j] && j != center) {
				can_make = false;
				break;
			}
		}
		if (can_make) {
			ans = max(ans, bit_count(i));
		}
		leaf.clear();
		middle.clear();
	}
	cout << ans << '\n';
	return 0;
}