#include <bits/stdc++.h>
#define next nnext

using namespace std;
vector<int> cur, next, temp;
int n, a, b, da, db;

int main() {
	cin >> n >> a >> b >> da>> db;
	int step = 0;
	cur.resize(n+1, 0);
	next.resize(n+1, 0);
	cur[a] = 1;
	next[b] = 1;

	while(true) {
		step++;
		temp.resize(n+1, 0);
		bool found = false;
		for (int i = 1 ; i <= n ; i++) {
			if (cur[i]) {
				int left = i - da;
				int right = i + da;
				if (left < 1) {
					left += n;
				}
				if (right > n) {
					right -= n;
				}
				temp[left] = 1;
				temp[right] = 1;
			}
		}
		for (int i = 1; i <= n ; i++) {
			if (next[i] && temp[i]) {
				found = true;
				break;
			}
		}
		if (found)
			break;
		step++;
		cur = temp;
		temp.clear();
		temp.resize(n+1, 0);
		for (int i = 1 ; i <= n ; i++) {
			if (next[i]) {
				int left = i - db;
				int right = i + db;
				if (left < 1) {
					left += n;
				}
				if (right > n) {
					right -= n;
				}
				temp[left] = 1;
				temp[right] = 1;
			}
		}
		for (int i = 1; i <= n ; i++) {
			if (cur[i] && temp[i]) {
				found = true;
				break;
			}
		}
		if (found)
			break;
		if (step > 2000)
			break;
		next = temp;
		temp.clear();

	}
	if (step >= 2000) {
		printf("Evil Galazy");
	}
	else printf("%d", step);

	return 0;
}