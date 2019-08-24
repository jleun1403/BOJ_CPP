#include <bits/stdc++.h>

using namespace std;
vector<pair<int, long long>> info;

bool cmp(pair<int, long long> &p1, pair<int, long long> &p2) {
	return p1.second < p2.second;
}

int num[3001];
int n, m;

int max_opponent() {
	int ret = 0;
	int index = 0;
	for (int i = 2 ; i <= m ; i++) {
		if (num[i] > ret) {
			ret = num[i];
			index = i;
		}
	}
	return index;
}


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0 ; i < n ; i++) {
		int a;
		long long b;
		scanf("%d %lld", &a, &b);
		info.push_back(make_pair(a, b));
		num[a] += 1;
	}
	long long answer = 0LL;
	vector<int> group;
	while(true) {
		int op = max_opponent();
		printf("%d %d %d\n", num[1], num[op], op);
		int my = num[1];
		for (int i = 1 ; i <= m ; i++) {
			if (num[i] == num[op])
				group.push_back(i);
		}
		if (my > num[op])
			break;
		if (my == num[op]) {
			long long t = 2000000000;
			for (int i = 0 ; i < n ; i++) {
				if (info[i].first != 1) {
					t = min(t, info[i].second);
				}
			}
			answer += t;
			break;
		}
		else {
			int need = num[op] + 1 - num[1];
			int count = 0;
			long long answer1 = 0;
			for (int i = 0 ; i < n ; i++) {
				bool flag = true;
				for (int j = 0 ; j < group.size() ;j++) {
					if (group[j] == info[i].first) {
						flag = false;
						break;
					}
				}
				if (flag) {
					count++;
				}
			}
			if (count >= need) {
				sort(info.begin(), info.end(), cmp);
				for (int i = 0 ; i < n && count ; i++) {
					bool flag = true;
					for (int j = 0 ; j < group.size() ;j++) {
						if (group[j] == info[i].first) {
							flag = false;
							break;
						}
					}
					if (flag) {
						answer1 += info[i].second;
						count--;
					}
				}
			}
			long long answer2 = 2000000000;
			int minindex;
			//int sup;
			for (int i = 0 ; i < n ; i++) {
				bool flag = false;
				for (int j = 0 ; j < group.size() ; j++) {
					if (info[i].first == group[j]) {
						if (answer2 > info[i].second) {
							answer2 = info[i].second;
							minindex = i;
						}
					}
				}
			}
			
			if (answer1 <= answer2) {
				answer += answer1;
				break;
			}

			answer += answer2;
			num[info[minindex].first] -= 1;
			info[minindex].first = 1;
			num[1] += 1;

			
			//printf("%lld %d\n", answer2, minindex);
		}
		group.clear();
	}
	cout << answer << '\n';
	return 0;
}