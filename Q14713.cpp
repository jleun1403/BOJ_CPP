#include <bits/stdc++.h>

using namespace std;
map<string, pair<int, int>> m;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	int total = 0;
	string temp;
	getline(cin, temp);
	n = stoi(temp);
	for (int k = 0 ; k < n ; k++) {
		string line;
		getline(cin, line);
		vector<string> ans;
		int len = 0;
		int start = 0;

		for (int i = 0 ; i <= line.length() ; i++) {
			if (i == line.length() || line[i] == ' ') {
				ans.push_back(line.substr(start, len));
				start = i + 1;
				len = 0;
			}
			else len ++;
		}
		for (int i = 0 ; i < ans.size() ; i++) {
			m[ans[i]] = make_pair(k+1, i+1);
		}
		total += ans.size();
		ans.clear();
	}
	string line;
	getline(cin, line);
	int len = 0;
	int start = 0;
	vector<string> ans;
	for (int i = 0 ; i <= line.length() ; i++) {
		if (i == line.length() || line[i] == ' ') {
			ans.push_back(line.substr(start, len));
			start = i + 1;
			len = 0;
		}
		else len ++;
	}
	int minarray[101];
	for (int i = 0 ; i <= 100 ; i++) {
		minarray[i] = 0;
	}
	if (ans.size() != total) {
		cout << "Impossible";
		return 0;
	}
	for (int i = 0 ; i < ans.size() ; i++) {
		auto p = m[ans[i]];
		cout << p.first << ' ' <<p.second << '\n';
		if (p.first == 0 || p.second == 0) {
			cout << "Impossible";
			return 0;
		}
		int line = p.first;
		if (minarray[line] > p.second) {
			cout << "Impossible";
			return 0;
		}
		else minarray[line] = p.second;
	}
	cout << "Possible";
}