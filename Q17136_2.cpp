#include <bits/stdc++.h>
using namespace std;
int n=10;
int a[10][10];
int remain[6];
int answer;
bool canput(int x, int y, int size){
    if(x +size >n || y+size > n) return false;
    if(remain[size] <=0) return false;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(a[x+i][y+j] ==0) return false;
        }
    }
    return true;
}
void solve(int x, int y, int sum){
    if(x == 10 && y ==0){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(a[i][j]){
                    return;
                }
            }
        }
        answer = min(answer, sum);
        return;
    }
    int nx= x;
    int ny = y+1;
    if(y == 9){
        nx=x+1;
        ny=0;
    }
    if(a[x][y] == 1){
        for(int k=1; k<=5; k++){
            if(canput(x,y,k)){
                remain[k]-=1;
                for(int i=0; i<k; i++){
                    for(int j=0; j<k; j++){
                        a[x+i][y+j] = 0;
                    }
                }
                solve(nx,ny, sum+1);
                remain[k] +=1;
                for(int i=0; i<k; i++){
                    for(int j=0; j<k; j++){
                        a[x+i][y+j] =1;
                    }
                }

            }
            
        }
    }
    else solve(nx,ny,sum);
}
int main(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    answer= 987654321;
    for(int i=1; i<=5; i++){
        remain[i] = 5;
    }
    solve(0,0,0);
    if(answer == 987654321) printf("-1\n");
    else printf("%d\n", answer);
    return 0;

}