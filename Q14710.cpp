#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	n %= 30;
	if (m % 12 == 0 && m / 12 == n) {
		printf("O");
	}
	else printf("X");

	return 0;
}