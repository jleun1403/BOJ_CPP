#include <bits/stdc++.h>

using namespace std;
int n;

int number(int x) {
	int start, end;
	start = (n-1) /x + 1;
	end = (n-1) / (x-1);
	return end - start + 1;
}

int main() {
	cin >> n;
	long long answer = 0;
	
	for (int i = 1 ; i <= min(n, 500000) ; i++) {
		answer += (n - 1) / i + 1;
	}
	if (n <= 500000) {
		cout << answer << '\n';
		return 0;
	}
	int temp = (n -1) / 500001;
	int k = 500001;
	while(true) {
		if ((n-1) / k != temp)
			break;
		k++;
	}
	for (int i = 500001 ; i < k ; i++) {
		answer += (n-1) / i + 1;
	} 

	for (int i = temp  ; i >= 2 ; i--) {
		//printf("%d %d %d\n", number(i) * i, number(i), i);
		answer += number(i) * i;
	}
	answer += 1;
	cout << answer << '\n';

	return 0;
}