#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool same(string s1, string s2) {
	if (s1.length() != s2.length())
		return false;
	for (int i = 0; i < s2.length(); i++) {
		string temp = s2.substr(i) + s2.substr(0, i);
		if (temp == s1)
			return true;
	}
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	vector<string> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		bool found = false;
		for (int k = 0; k < v.size(); k++) {
			if (same(s, v[k])) {
				found = true;
				break;
			}
		}
		if (!found) {
			v.push_back(s);
		}
	}
	cout << v.size();
}