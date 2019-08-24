#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	int n = s.length();
	bool a = false, b = false, c = false, d = false;
	for (int i = 0 ; i < n ; i++) {
		if (s[i] == 'U') {
			a = true;
		}
		if (a && s[i] == 'C') {
			b = true;
		}
		if (b && s[i] == 'P') {
			c = true;
		}
		if (c && s[i] == 'C') {
			d = true;
		}
	}
	if (a && b && c && d) {
		printf("I love UCPC\n");
	}
	else printf("I hate UCPC\n");

	return 0;
}