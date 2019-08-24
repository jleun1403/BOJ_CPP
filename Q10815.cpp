#include <bits/stdc++.h>
using namespace std;
int a[500001];
int b[500001];

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        scanf("%d", &b[i]);
        int left = 0, right = n-1, mid = 0;
        bool check = false;
        while(left<=right){
            mid = (left+right)/2;
            if(a[mid] == b[i]){
                printf("1 ");
                check = true;
                break;
            }
            else if(b[i] < a[mid]){
                right = mid-1;
            }
            else left = mid+1;
        }
        if(check == false) {
            printf("0 ");
        }

    }
    return 0;


}