#include <bits/stdc++.h>

using namespace std;

int char_to_int(char x) {
	if (x <= '9')
		return x - '0';
	else return x - 'A' + 10;
}

char int_to_char(int x) {
	if (x <= 9)
		return x + '0';
	else return x + 'A' - 10;
}


bool cmp(pair<string, char> &s1, pair<string, char> &s2) {
	for (int i = 0 ; i < 70 ; i++) {
		if (s1.first[i] < s2.first[i])
			return true;
		else if (s1.first[i] > s2.first[i])
			return false;
	}
	return false;
}

string sum(string &s1, string &s2) {
	string ret = "";
	for (int i = 0 ; i < 70 ; i++) {
		ret += "0";
	}
	for (int i = 69 ; i >= 0 ; i--) {
		ret[i] = char_to_int(ret[i]);
		ret[i] += char_to_int(s1[i]) + char_to_int(s2[i]);
		if (ret[i] >= 36) {
			ret[i] -= 36;
			ret[i-1] = '1';
		}
		ret[i] = int_to_char(ret[i]);
	}
	return ret;
}

int main() {
	vector<pair<string, char>> changed;
	vector<vector<string>> v(37);
	int n, k;
	cin >> n;
	for (int i = 0 ; i < n ; i++) {
		string s;
		cin >> s;
		if (s == "0") {
			s = "[";
		}
		string t = "";
		int k = 70 - s.length();
		for (int j = 0 ; j < k ; j++) {
			t += "0";
		}
		t += s;
		for (int j = 0 ; j < 37 ; j++) {
			v[j].push_back(t);
		}
	}
	cin >> k;
	for (int i = 0 ; i < 36 ; i++) {
		char target = int_to_char(i);
		bool change = false;
		for (int j = 0 ; j < n ; j++) {
			if ( i == 0)
				change = false;
			else change = true;
			for (int k = 0 ; k < v[i][j].length() ; k++) {
				if (!change && v[i][j][k] != '0') {
					change = true;
				}
				if (v[i][j][k] == target && change) {
					v[i][j][k] = 'Z';
				}
				if (v[i][j][k] == '[') {
					if (target == '0') {
						v[i][j][k] = 'Z';
					}
					else v[i][j][k] = '0';
				}
			}
		}
		string sum_of_change = "";
		for (int j = 0 ; j < 70 ; j++) {
			sum_of_change += "0";
		}
		for (int j = 0 ; j < n ; j++) {
			sum_of_change = sum(sum_of_change, v[i][j]);
		}
		changed.push_back(make_pair(sum_of_change, target));
	}	
	sort(changed.begin(), changed.end(), cmp);
	reverse(changed.begin(), changed.end());

	vector<char> have_to_change;
	for (int i = 0 ; i < k ; i++) {
		have_to_change.push_back(changed[i].second);

	}

	for (int i = 0 ; i < k ; i++) {
		char target = have_to_change[i];
		bool change = false;
		for (int j = 0 ; j < n ; j++) {
			if (target == '0')
				change = false;
			else change = true;
			for (int k = 0 ; k < v[36][j].length() ; k++) {
				if (!change && v[36][j][k] != '0') {
					change = true;
				}
				if (v[36][j][k] == target && change) {
					v[36][j][k] = 'Z';
				}
				if (v[36][j][k] == '[') {
					if (target == '0')
						v[36][j][k] = 'Z';
				}
			}
		}
	}
	for (int j = 0 ; j < n ; j++) {
		for (int k = 0 ; k < v[36][j].length() ; k++) {
			if (v[36][j][k] == '[')
				v[36][j][k] = '0';
		}
	}


	string answer = "";
	for (int i = 0 ; i < 70 ; i++) {
		answer += "0";
	}
	for (int i = 0 ; i <n ; i++) {
		answer = sum(answer, v[36][i]);
	}

	bool zero = false;
	for (int i = 0 ; i < 70 ; i++) {
		if (answer[i] != '0')
			zero = true;
		if (zero) {
			printf("%c", answer[i]);
		}
	}
	if (!zero)
		printf("0");
	printf("\n");

	return 0;
}