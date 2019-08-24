#include <bits/stdc++.h>
#define MAX_N 1000000
using namespace std;
bool isPrime[1000001];

void Sieve(){
	memset(isPrime, true, sizeof(isPrime));
	isPrime[1] = false;
	for (int i = 2 ; i*i <= MAX_N ; i++) {
		if (isPrime[i]) {
			for (int j = i*i ;  j <= MAX_N ; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

bool can_divide(string &s, int r) {
	int ret = 0;
	for (int i = 0 ; i < s.length() ; i++) {
		ret = (ret * 10 + s[i] - '0') % r;
	}
	return ret == 0;
}

int main() {
	string s;
	int k;
	Sieve();
	cin >> s >> k;
	for (int i = 1 ; i < k ; i++) {
		if (isPrime[i] && can_divide(s, i)) {
			cout << "BAD ";
			if (s.length() > 15) {
				cout << i << '\n';
			}
			else {
				long long t = stoll(s);
				cout << min((long long)i, t / i);
			}
			return 0;
		}
	}
	cout << "GOOD"<<'\n';

	return 0;
}