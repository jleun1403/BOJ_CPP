#include <bits/stdc++.h>
using namespace std;
int a[101][101];
int b[101][101];
int main(){
    int n, m;
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
    //가로줄 탐색
    for (int i = 0; i < n; i++){
        ok = true;
        num = 0; // 최소 여기까진 ok 확인됨.
        for (int j = 0; j < n; j++){
            if(j == n-1){
                ok = true;
                break;

            }
            else if (a[i][j] == a[i][j + 1]){ // 2(i,j) -> 2(i+1, j)
                //num+=1;
                continue;
            }
            else if ( a[i][j] == a[i][j + 1] - 1){ // 2(i,j) -> 3(i,j+1)
                if (j - m + 1 >=0 && j-m+1 >= num){
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
                    j+=m;
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
                    if(ok == true){
                    num = j+m+1;
                    i+=m;
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
            cout << "i= " << i << '\n';
            ans += 1;
        }
    }

    cout << ans << '\n';
    // 세로줄 탐색
    for (int j = 0; j < n; j++){
        ok = true;
        num=0;
        for (int i = 0; i < n; i++){
            if(i == n-1){
                ok = true;
                break;
            }
            else if (a[i][j] == a[i + 1][j]){
                continue;
            }
            else if (a[i][j] == a[i + 1][j] - 1){ // 2(i,j) ->3 (i+1,j)
                if(i-m+1 >=0 && i-m+1 >= num){
                    for (int k = i; k >= i - m+1; k--){
                        if (a[k][j] == a[i][j]){
                            continue;
                        }
                        else{
                            ok = false;
                            break;
                        }
                    }
                    num = i;
                    //i+=m;

                }
                else {
                    ok = false;
                    break;
                }
            }
            else if (a[i][j] == a[i + 1][j] + 1){ // 3(i,j) -> 2(i+1,j)
                if(i+m <n){
                    for (int k = i+1; k <= i + m; k++){
                        if (a[k][j] == a[i][j]){
                            continue;
                        }
                        else{
                            ok = false;
                            break;
                        }
                    }
                    if(ok == true){
                        //i+=m-1;
                        num = i+m+1;
                        i+=m;
                    }
                }
                else{
                    ok = false;
                    break;
                }
            }
            else{
                ok = false;
                break;
            }
        }
        if (ok == true){
            cout << "j= " << j << '\n';
            ans += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}