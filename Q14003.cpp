#include <bits/stdc++.h>
#define inf 1500000000
using namespace std;
int _index_[1000001];
int value[1000001];
vector<int> v;
vector<int> lis;


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0 ; i < n ;i++) {
		int a;
		scanf("%d", &a);
		value[i+1] = a;
		v.push_back(a);
	}
	lis.push_back(-inf);
	for (int i = 0 ; i < n ; i++) {
		if (v[i] > lis.back()){
			_index_[i] = lis.size();
			lis.push_back(v[i]);
		}
		else {
			auto it = lower_bound(lis.begin(), lis.end(), v[i]);
			_index_[i] = (int)(it - lis.begin());
			*it = v[i];
		}
	}
	int ans = lis.size() - 1;
	stack<int> st;
	printf("%d\n", ans);
	/*for (int i = n-1 ; i >=0 ; i--) {
		if (_index_[i] == ans) {
			st.push(value[i+1]);
			ans--;
		}
	}
	while(!st.empty()) {
		printf("%d ", st.top());
		st.pop();
	}*/
	
	return 0;
}