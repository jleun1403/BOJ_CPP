#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int sum = 0;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(a == 1) sum+=1;
    }
    if(sum < (n+1)/2) printf("Junhee is not cute!\n");
    else printf("Junhee is cute!\n");
    return 0;
}