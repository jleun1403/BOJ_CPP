#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=9; i++){
        a[i] = i;
    }
    int cnt = 10;
    for(int i=10; i<=1000000; i+=10){
        for(int j=0; j<i/10; j++){
            a[cnt++] = i+j;
        }
    }
}