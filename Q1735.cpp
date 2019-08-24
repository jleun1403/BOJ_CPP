#include <bits/stdc++.h>

using namespace std;
int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int up = a*d + b*c;
	int down = b*d;
	int _gcd = gcd(up, down);
	cout << up / _gcd << ' ' << down / _gcd ;
	return 0;
}