#include <bits/stdc++.h>

using namespace std;
vector<char> v;
bool isPalindrome(int x, int y) {
	if (x >= y)
		return true;
	if (v[x] != v[y])
		return false;
	return isPalindrome(x+1, y-1);
}

int main() {
	string s;
	cin >> s;
	for (int i = 0 ; i < s.length() ; i++) {
		v.push_back(s[i]);
	}
	if (isPalindrome(0, s.length() -1)) {
		cout << "1";
	}
	else cout << "0";
	return 0;
}