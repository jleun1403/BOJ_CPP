#include <bits/stdc++.h>

using namespace std;

int main() {
	int x;
	scanf("%d", &x);
	int divisor = 2;
	bool div = false;
	int leaf = 0;
	while(true) {
		if (x == divisor) {
			leaf++;
			break;
		}
		else if (x < divisor) {
			break;
		}
		if (x % divisor == 0) {
			div = true;
			while(true) {
				x /= divisor;
				leaf++;
				if (x % divisor != 0)
					break;
			}
		}
		divisor++;
	}

	int t = 1;
	int ans = 0;
	while(t < leaf) {
		t *= 2;
		ans++;
	}


	printf("%d\n", ans); 
	return 0;
}