#include <bits/stdc++.h>

using namespace std;


int main(){
	int n = 1;
	int c;
	scanf("%d", &c);
	while(c != 1) {
		if (c % 2)
			c = 3*c + 1;
		else c = c/2;
		n++;
	}
	printf("%d\n", n);
	return 0;
}