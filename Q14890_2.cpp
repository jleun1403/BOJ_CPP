#include <bits/stdc++.h>
using namespace std;
int a[101][101];
int b[101][101];
int n, m;
int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &a[i][j]); 
            }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            b[i][j] = a[j][i];
        }
    }
    int ans = 0;
    bool ok = true;
    int num = 0;
    for (int i = 0; i < n; i++){
        ok = true;
        num = 0; // 최소 여기까진 ok 확인됨.
        for (int j = 0; j < n-1; j++){
            if (a[i][j] == a[i][j + 1]){ // 2(i,j) -> 2(i+1, j)
                continue;
            }
            else if ( a[i][j] == a[i][j + 1] - 1){ // 2(i,j) -> 3(i,j+1)
                if (j - m + 1 >=0 && ((num==0 && j-m+1 >=num) || (num!=0 && j-m+1 > num))){
                    for (int k = j; k >= j - m + 1; k--){
                        if (a[i][k] == a[i][j]){
                            continue;
                        }
                        else{
                            ok = false;
                            break;
                        }
                    }
                    num = j;
                }
                else{
                    ok = false;
                    break;
                }
            }
            else if (a[i][j] == a[i][j + 1] + 1){ // 3(i,j) -> 2(i,j+1);
                if (j +m <n){
                    for (int k = j + 1; k <= j +m; k++){
                        if (a[i][k] == a[i][j + 1]){
                            continue;
                        }
                        else{
                            ok = false;
                            break;
                        }
                    }
                    num = j+m;    
                }
                else{
                    ok = false;
                    break;
                    }
                }
                else {
                    ok = false;
                    break;
                }
        }
        if (ok == true){ 
            ans += 1;
        }
    }
    for (int i = 0; i < n; i++){
        ok = true;
        num = 0; // 최소 여기까진 ok 확인됨.
        for (int j = 0; j < n-1; j++){
            if (b[i][j] == b[i][j + 1]){ // 2(i,j) -> 2(i+1, j)
                continue;
            }
            else if ( b[i][j] == b[i][j + 1] - 1){ // 2(i,j) -> 3(i,j+1)
                if (j - m + 1 >=0 && ((num==0 && j-m+1 >=num) || (num!=0 && j-m+1 > num))){
                    for (int k = j; k >= j - m + 1; k--){
                        if (b[i][k] == b[i][j]){
                            continue;
                        }
                        else{
                            ok = false;
                            break;
                        }
                    }
                    num = j;
                }
                else{
                    ok = false;
                    break;
                }
            }
            else if (b[i][j] == b[i][j + 1] + 1){ // 3(i,j) -> 2(i,j+1);
                if (j +m <n){
                    for (int k = j + 1; k <= j +m; k++){
                        if (b[i][k] == b[i][j + 1]){
                            continue;
                        }
                        else{
                            ok = false;
                            break;
                        }
                    }
                    if(ok == true){
                    num = j+m;
                    }
                }
                else{
                    ok = false;
                    break;
                    }
                }
                else {
                    ok = false;
                    break;
                }
        }
        if (ok == true){
            ans += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}