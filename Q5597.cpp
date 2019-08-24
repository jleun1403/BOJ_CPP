#include <bits/stdc++.h>
using namespace std;
bool check[31];
int main(){
    int n;
    for(int i=0; i<28; i++){
        cin >> n;
        check[n] = true;
    }
    for(int i=1; i<=30; i++){
        if(!check[i]){
            printf("%d\n", i);
        }
    }
    return 0;
}