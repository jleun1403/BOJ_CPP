#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	vector<int> a;
	vector<int> b;
	scanf("%d %d", &n, &m);
	for (int i = 0 ; i < n ; i++){
		int x; scanf("%d", &x);
		a.push_back(x);
	}
	for (int i = 0 ; i < m ; i++) {
		int x; scanf("%d", &x);
		b.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<int> answer;
	for (int i = 0 ; i < n ; i++) {
		if (!binary_search(b.begin(), b.end(), a[i]))
			answer.push_back(a[i]);
	}
	printf("%d\n", answer.size());
	for (int i = 0 ; i < answer.size() ; i++) {
		printf("%d ", answer[i]);
	}
}