#include <bits/stdc++.h>

using namespace std;

int lowest(int x) {
	int m;
	for (int i = 0 ; i < 30 ; i++) {
		if ((1<<i) > x) {
			m = (1<<i);
			break;
		}
	}
	return m / 2;
}

int bit_count(int x) {
	int ret = 0;
	for (int i = 0 ; i < 30 ; i++) {
		if ((1<<i) & x)
			ret++;
	}
	return ret;
}

int closest(int x) {
	int m;
	for (int i = 0 ; i < 30 ; i++) {
		if ((1<<i) >= x) {
			m = (1<<i);
			break;
		}
	}
	return m + m - x;
}

int main() {
	
	int a, b;
	cin >> a>> b;
	if ((a + b) % 2) {
		printf("-1");
		return 0;
	}
	int same = (a + b) / 2;
	int diff = max(a, b) - same;
	
	int same1 = closest(same);
	int diff1 = closest(diff);
	int hint = 0;
	int min_bit = 30;

	if (!(same & diff)) {
		if (bit_count(same | diff) < min_bit) {
			min_bit = bit_count(same | diff);
			hint = 1;
		}
	}
	if (!(same & diff1)) {
		if (bit_count(same | diff1) < min_bit) {
			min_bit = bit_count(same | diff1);
			hint = 2;
		}
	}
	if (!(same1 & diff)) {
		if (bit_count(same1 | diff) < min_bit) {
			min_bit = bit_count(same1 | diff);
			hint = 3;
		}
	}
	if (!(same1 & diff1)) {
		if (bit_count(same1 | diff1) < min_bit) {
			min_bit = bit_count(same1 | diff1);
			hint = 4;
		}
	}
	if (hint == 0) {
		printf("-1");
		return 0;
	}


	vector<int> answer;
	int temp;
	if (hint == 1) {
		for (int i = 0 ; i < 30; i++) {
			if ((1<<i) & same) {
				answer.push_back((1<<i));
			}
		}
		temp = answer.size();
		for (int i = 0 ; i < 30 ; i++) {
			if ((1<<i) & diff) {
				answer.push_back((1<<i));
			}
		}
	}
	if (hint == 2) {
		for (int i = 0 ; i < 30; i++) {
			if ((1<<i) & same) {
				answer.push_back((1<<i));
			}
		}
		temp = answer.size();
		for (int i = 29 ; i >= 0 ; i--) {
			if (diff1 & (1<<i)) {
				answer.push_back((1<<i));
				diff1 -= (1<<i);
				break;
			}
		}
		for (int i = 0 ; i < 29 ; i++) {
			if (diff1 & (1<<i)) {
				answer.push_back(-(1<<i));
			}
		}
	}
	if (hint == 3) {
		for (int i = 29 ; i >= 0 ; i--) {
			if (same1 & (1<<i)) {
				answer.push_back((1<<i));
				same1 -= (1<<i);
				break;
			}
		}
		for (int i = 0 ; i < 29 ; i++) {
			if (same1 & (1<<i)) {
				answer.push_back(-(1<<i));
			}
		}
		temp = answer.size();
		for (int i = 0 ; i < 30; i++) {
			if ((1<<i) & diff) {
				answer.push_back((1<<i));
			}
		}
	}
	if (hint ==4 ) {
		for (int i = 29 ; i >= 0 ; i--) {
			if (same1 & (1<<i)) {
				answer.push_back((1<<i));
				same1 -= (1<<i);
				break;
			}
		}
		for (int i = 0 ; i < 29 ; i++) {
			if (same1 & (1<<i)) {
				answer.push_back(-(1<<i));
			}
		}
		temp = answer.size();
		for (int i = 29 ; i >= 0 ; i--) {
			if (diff1 & (1<<i)) {
				answer.push_back((1<<i));
				diff1 -= (1<<i);
				break;
			}
		}
		for (int i = 0 ; i < 29 ; i++) {
			if (diff1 & (1<<i)) {
				answer.push_back(-(1<<i));
			}
		}
	}





	
	
	printf("%d\n", answer.size() + 1);
	int curx = 0, cury = 0;
	printf("0,0\n");
	for (int i = 0 ; i < temp ; i++) {
		printf("%d,%d\n", curx+ answer[i], cury+answer[i]);
		curx += answer[i];
		cury += answer[i];
	}
	for (int i = temp ; i < answer.size() ; i++) {
		if (a >= b) {
			printf("%d,%d\n", curx + answer[i], cury-answer[i]);
			curx += answer[i];
			cury -= answer[i];
		}
		else { 
			printf("%d,%d\n", curx-answer[i], cury + answer[i]);
			curx -= answer[i];
			cury += answer[i];
		}
	}


	return 0;
}