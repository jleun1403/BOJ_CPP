#include <bits/stdc++.h>
using namespace std;
int n, leng;
int a[101][101];
int b[101][101];
int answer;

bool isok(int i){
    bool ok = true;
    int it = 1;
    for(int j=1; j<=n-1; j++){
        if(a[i][j] == a[i][j+1]){// 2 -> 2
            continue;
        }
        else if(a[i][j]== a[i][j+1]+1){ //3 -> 2
            for(int k=j+1; k<=j+leng; k++){
                if(a[i][k] != a[i][j+1]) {
                    ok= false;
                    break;
                }
            }
            it =j+leng+1; 
        }
        else if(a[i][j] ==a[i][j+1]-1) { // 2 ->3
            if(j-leng+1 <1 || j-leng+1 < it) {
                ok = false;
                break;
            }
            for(int k = j; k>=j-leng+1; k++){
                if(a[i][k] != a[i][j]) {
                    ok = false;
                    break;
                }
            }
            it= j+1;
            ok = true;
        }
        else {
            ok = false;
            break;
        }
    }
  if(ok == true) return true;
  else return false;
}
int main(){
    cin >> n>> leng;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j] ;
            b[j][i] = a[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        if(isok(i)) {
            answer+=1;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            a[i][j] = b[i][j];
        }
    }
    for(int i=1 ; i<=n; i++){
        if(isok(i)){
           // cout << i << '\n';
            answer +=1;
        }
    }
    cout << answer << '\n';
    return 0;
}
//112333 false 