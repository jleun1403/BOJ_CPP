#include <bits/stdc++.h>

using namespace std;
long long q[100000];
long long r[100000];
long long sqq[100000];
long long tqq[100000];

long long gcd(long long x, long long y) {
	if ( y == 0) return x;
	else return gcd(y, x % y);
}

pair<long long, long long> Euclid(long long a, long long b) {
	memset(r, -1, sizeof(r));
	r[0] = a;
	r[1] = b;
	sqq[0] = 1LL; 
	sqq[1] = 0;
	tqq[0] = 0; 
	tqq[1] = 1LL;
	for (int i = 2 ; i < 100000 ; i++) {
		r[i] = r[i-2] % r[i-1];
		q[i-1] = r[i-2] / r[i-1];
		sqq[i] = sqq[i-2] - q[i-1]*sqq[i-1];
		//printf("%d %d %d\n", sqq[i] , sqq[i-2], sqq[i-1]);
		tqq[i] = tqq[i-2] - q[i-1]*tqq[i-1];
		//printf("here : %d %d %d %d\n", r[i], q[i-1], sqq[i], tqq[i]);
		if (r[i] == 0) {
			if (r[i-1] == -1) {
				return make_pair(sqq[i], tqq[i]);
			}	
			return make_pair(sqq[i-1], tqq[i-1]);
		}
	}
}

int main() {
	int testcase;
	cin >> testcase;
	while(testcase--) {
		long long a, b;
		cin >> a>> b;
		if (a == 1 && b == 1) {
			cout << '2' << '\n';
			continue;
		}
		else if (a == 1) {
			cout << '1' << '\n';
			continue;
		}
		else if (b == 1) {
			if (a == 1000000000)
				cout << "IMPOSSIBLE" << '\n';
			else cout << a + 1 << '\n';
			continue;
		}
		if (gcd(a, b) != 1) {
			cout << "IMPOSSIBLE" << '\n';
			continue;
		} 
		pair<long long, long long> answer = Euclid(a, b);
		if (answer.second > 1e9) {
			cout << "IMPOSSIBLE" << '\n';
		}

		else if (answer.second < 0) {
			while(answer.second < 0) {
				answer.second += a;
			}
			cout << answer.second << '\n';
		}
		else {
			cout << answer.second << '\n';
		}
	}
	return 0;
}