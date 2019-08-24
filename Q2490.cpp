#include <bits/stdc++.h>
using namespace std;

int main(){
    for(int i=0; i<3; i++){
        int a[4];
        for(int i=0; i<4; i++){
            scanf("%d", &a[i]);
        }
        sort(a,a+4);
        int cnt = 0; // count 0
        for(int i=0; i<4; i++){
            if(a[i] == 0){
                cnt+=1;
            }
            else break;
        }
        if(cnt == 0){
            printf("E\n");
        }
        else if (cnt ==1){
            printf("A\n");
        }
        else if(cnt == 2){
            printf("B\n");
        }
        else if(cnt==3){
            printf("C\n");
        }
        else printf("D\n");
        
    }
    return 0;
}