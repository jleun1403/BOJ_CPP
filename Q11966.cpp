#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0 ; i <= 30 ; i++) {
		if ((1<<i) == n) {
			printf("1");
			return 0;
		}
	}
	printf("0");	
	return 0;
}