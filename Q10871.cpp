#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x , num;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        if(num <x) printf("%d ", num);
    }
    return 0;
}