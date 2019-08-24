// Q9465.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	
	int testcase;
	cin >> testcase;
	for (int test = 0; test < testcase; test++) {
		int n;
		cin >> n;
		vector<vector<int>> D(2, vector<int>(n + 1));
		D[0][0] = D[1][0] = 0;
		for (int i = 0; i < n; i++)
			cin >> D[0][i + 1];
		for (int i = 0; i < n; i++)
			cin >>D[1][i + 1];
		for (int i = 2; i <= n; i++) {
			D[0][i] = max(D[1][i - 1] + D[0][i], D[1][i - 2] + D[0][i]);
			D[1][i] = max(D[0][i - 1] + D[1][i], D[0][i - 2] + D[1][i]);
		}
		cout << max(D[0][n], D[1][n]) << endl;
	}

}

