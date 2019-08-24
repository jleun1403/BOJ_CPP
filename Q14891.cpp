#include <bits/stdc++.h>
using namespace std;
int a[5][9];
int sum;
void solve(int m, int t){
    int temp[9];
    if(t == -1){ 
        temp[8]= a[m][1];
        for(int i=1; i<=7; i++){
            temp[i]= a[m][i+1];
        }
    }
    else{ // clockwise
        temp[1] =a[m][8];
        for(int i=8; i>=2; i--){
            temp[i]=a[m][i-1];
        }
    }
    for(int i=1; i<=8; i++){
        a[m][i] = temp[i];
    }
}
int main(){
    for(int i=1; i<=4; i++){
        for(int j=1; j<=8; j++){
        scanf("%1d", &a[i][j]);
        }
    }
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n, m;
        scanf("%d %d", &n, &m);
        if(n == 1){
            while(true){
                if(a[1][3] == a[2][7]){
                    solve(1,m);
                    break;
                }
                else{
                    if(a[2][3] == a[3][7]) {
                        solve(1,m);
                        solve(2,-m);
                        break;
                    }
                    else{ 
                        if(a[3][3] == a[4][7]){ 
                            solve(1, m);
                            solve(2, -m);
                            solve(3, m);
                            break;
                        }
                        else{
                            solve(1, m);
                            solve(2, -m);
                            solve(3, m);
                            solve(4, -m);
                            break;
                        }
                    }
                }
            
            }
        }
        else if(n ==2){
                if(a[1][3] != a[2][7]){
                     solve(1,-m);
                 } 
                 while(true){
                     if(a[2][3]== a[3][7]) {
                         solve(2,m);
                        break;
                        } 
                    else{
                        if(a[3][3] ==a[4][7]) {
                            solve(2, m);
                            solve(3, -m);
                                break;
                            }
                        else{ // 1,2,3,4 다 회전
                              solve(2, m);
                              solve(3, -m);
                              solve(4, m);
                              break;
                            }
                        }
                    }
                }
        else if (n==3){
                if(a[3][3] != a[4][7]){
                     solve(4,-m);
                 }
                     while(true){
                        if(a[3][7] == a[2][3]){
                         solve(3,m);
                           break;
                           }
                        else{
                            if(a[1][3] == a[2][7]){
                                   solve(3,m);
                                   solve(2,-m);
                                   break;
                            }
                            else{
                                  solve(3,m);
                                  solve(2,-m);
                                  solve(1,m);
                                  break;
                                }
                            }
                        }
                    }
                
        else{ //(n==4)
            while(true){
                if(a[3][3] == a[4][7]){
                    solve(4,m);
                   break;
                    }
                else{
                    if(a[2][3] == a[3][7]){
                      solve(4,m);
                      solve(3,-m);
                        break; }
                    else{
                        if(a[1][3] == a[2][7]){
                            solve(4,m);
                            solve(3,-m);
                            solve(2,m);
                            break;  
                        }
                        else{
                            solve(4,m);
                            solve(3,-m);
                            solve(2,m);
                            solve(1,-m);
                            break;
                        }
                    }
                }
            }
        }
    }
    if(a[1][1] == 1){
        sum+=1;
    }
    if(a[2][1] == 1){
        sum+=2;
    }
    if(a[3][1] == 1){
        sum+=4;
    }
    if(a[4][1] == 1){
        sum+=8;
    }
    cout << sum << '\n';
    return 0;
}