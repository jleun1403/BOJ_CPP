#include <bits/stdc++.h>

using namespace std;

int dp[1003][1003];
int n;
int quest[101][3];
bool visited[101];

int go(int Str, int Int) {
	if (dp[Str][Int] != -1) 
		return dp[Str][Int];
	int ret = 0;
	int cnt = 0;
	int points = 0;
	vector<int> from_here;
	for (int i = 0 ; i < n ; i++) {
		if (quest[i][0] <= Str || quest[i][1] <= Int) {
			if (!visited[i]) {
				points += quest[i][2];
				from_here.push_back(i);
				visited[i] = true;
				cnt++;
			}
			ret += 1;
		}
	}
	if(cnt == 0)
		return dp[Str][Int] = ret;
	for (int i = Str; i <= min(1000, Str + points) ; i++) {
		int next_Int = min(1000, Int + points - (i - Str));
		ret = max(ret, go(i, next_Int));
	}
	for (int &s : from_here) {
		visited[s] = false;
	}
	return dp[Str][Int] = ret;
}

int main() {
	memset(visited, false, sizeof(visited));
	memset(dp ,-1, sizeof(dp));
	scanf("%d", &n);
	for (int i= 0 ; i < n ;i++) {
		scanf("%d %d %d", &quest[i][0], &quest[i][1], &quest[i][2]);
	}
	
	printf("%d\n", go(1, 1));

	return 0;
}