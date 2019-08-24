#include <bits/stdc++.h>

using namespace std;
char answer[100];
vector<int> capacity(26);

bool possible(int x, int y) {
	if (x > y) return true;
	if (x == y) {
		for (int i = 0 ; i < 26 ; i++) {
			if (capacity[i] > 0)
				answer[x] = i + 'a';
		}
		return true;
	}

	char first;
	for (int i = 0 ; i < 26 ; i++) {
		if (capacity[i] > 0) {
			first = i + 'a';
			capacity[i] -= 1;
			break;
		}
	}
	answer[x] = first;
	for (int i = 25 ; i >= 0 ; i--) {
		if (capacity[i] > 0 ) {
			if (i+'a' <= first)
				break;
			capacity[i]--;
			answer[y] = i+'a';
			if (possible(x+1, y-1)) {
				return true;
			}
			capacity[i]++;
		}
	}
	capacity[first - 'a'] += 1;
	return false;

}


int main() {
	string s;
	cin >> s;

	for (int i = 0 ; i < s.length() ; i++) {
		capacity[s[i]- 'a'] += 1;
	}
	if (possible(0, s.length()-1)) {
		for (int i = 0 ; i < s.length() ; i++) {
			printf("%c", answer[i]);
		}
		printf("\n");
	}
	else printf("-1");

	return 0;
}