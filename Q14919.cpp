#include <bits/stdc++.h>

using namespace std;
int a[1000001];

int main() {
	int m;
	double t;
	scanf("%d", &m);
	while(scanf("%lf", &t) == 1) {
		int x = (int)(t * 1000000 + 0.5);
		
		a[x] += 1;
		//printf("%d %d\n", x, a[x]);
	}
	int cnt = 0;
	int limit = 1000000;
	for (int i = 0 ; i <= 1000000 ; i++) {
		if (i * m >= limit) {
			printf("%d ", cnt);
			limit += 1000000;
			cnt = a[i];
		}
		else {
			cnt += a[i];
		}
	}

	return 0;
}