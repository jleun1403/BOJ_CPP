#include <bits/stdc++.h>
#define mod 1000000007
int count;
bool dead_end;
int cycle_count;
int group[1000001];
int visited[1000001];
int v[1000001];
long long dp[1000001];

long long mypow(long long n, long long k) {
	//if (k == -1) return 0;
	//if (n == 0) return 0LL;
	if (k == 0) return 1LL;
	if (k == 1) return n % mod;
	if (k%2 == 0) {
		long long temp = (mypow(n, k/2)) % mod;
		return (temp * temp)% mod;
	}
	else {
		long long temp = (mypow(n,k-1)) % mod;
		return (temp * n) % mod;
	}
}



 /* void DFS(int node, int groupnum) {
	visited[node] = ++count;
	group[node] = groupnum;
	int next = v[node];
	if (visited[next] == -1) {
		DFS(next, groupnum);
	} 
	else {
		if (groupnum == group[node]) {
			cycle_count = count - visited[next] + 1;
		}
		else {
			dead_end = true;
		}
	}
}

*/

int main() {
	long long n, k;
	scanf("%lld %lld", &n, &k);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d", &v[i]);

	}

	memset(visited, -1, sizeof(visited));
	int groupnum = 0;
	long long ans = 1;

	dp[1] = k;
	dp[2] = k*(k-1) % mod;
	dp[3] = (((k *(k-1)) % mod) *(k-2)) % mod;
	for (int i = 4 ; i <= n ; i++) {
		dp[i] = dp[i-2]*(k-1) + dp[i-1]*(k-2);
		dp[i] %= mod;
	}

	for (int i = 1 ; i <= n ; i++) {
		count = 0;
		cycle_count = 0;
		dead_end = false;
		long long temp = 0;
		if (visited[i] == -1) {
			groupnum++;
			visited[i] = ++count;
			group[i] = groupnum;
			int next = i;
			while(true) {
				next = v[next];
				if (visited[next] == -1) {
					group[next] = groupnum;
					visited[next] = ++count;
				}
				else {
					if (groupnum == group[next]) {
						cycle_count = count - visited[next] + 1;
					}
					else {
						dead_end = true;
					}
					break;
				}
			}


			//DFS(i, groupnum);
			if (dead_end) {
				ans *= mypow(k-1, count);
			}
			else {
				ans *= dp[cycle_count];
				ans %= mod;
				ans *= mypow(k-1, count - cycle_count);
			}
			ans %= mod;
		}
		
	}
	printf("%lld\n", ans);
	return 0;
}