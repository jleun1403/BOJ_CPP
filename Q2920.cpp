#include <bits/stdc++.h>
using namespace std;
int a[10];
int main(){
    for(int i=0; i<8; i++){
        scanf("%d", &a[i]);
    }
    bool as = true, dc = true, mx = true;
    for(int i=0; i<7; i++){
        if(a[i] < a[i+1]){
            continue;
        }
        else{
            as = false;
            break;
        }
    }
    for(int i=0; i<7; i++){
        if(a[i] > a[i+1]) continue;
        else {
            dc = false;
            break;
        }
    }
    if(as == false && dc == false) printf("mixed\n");
    else{
        if(as == true) printf("ascending\n");
        else printf("descending\n");
    }
    return 0;
}