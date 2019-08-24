#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
	int n;
	long long m;
	scanf("%d %lld", &n, &m);
	
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
    long long ans=a[n-1]*m;
	long long left = 1;
	long long mid;
	long long right= a[n-1]*m;
	long long sum;
	while(left < right){
		mid = (left+right)/2;
		sum =0;
		for(int i=0; i<n; i++){
			sum+=mid/a[i];
		}
		if(sum >=m){
			ans = mid;
			right = mid;
		}
		else
			left = mid+1;
	}
	cout << ans << '\n';
	return 0;
}