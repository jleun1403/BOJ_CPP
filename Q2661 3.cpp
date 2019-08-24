#include <bits/stdc++.h>
using namespace std;
int n;
int a[101];
bool check(int position, int k){
	a[position] = k;
	for(int i =2; i<=position/2; i++){
		int start1 = position - 2*i +1;
		int start2 = position - i  +1 ;
		//if(start1 <=0) break;
		int cnt = 0;
		for(int j=0; j<i; j++){
			if(a[start1+j] == a[start2+j]){
				cnt +=1;
			}
		}
		if(cnt == i) return false;

	}
	return true;
}
void go(int x){
    if(x == n+1){
        for(int i=1; i<=n; i++){
            cout << a[i];
        }
        exit(0);
    }
    for(int i=1; i<=3; i++){
        if(a[x-1] ==i) continue;
        else{
            a[x] = i;
            if(check(x,i)) {
                go(x+1);
            }
        }
    }
}
int main(){
    cin >> n;
    go(1);
    return 0;
}