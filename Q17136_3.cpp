#include <bits/stdc++.h>
using namespace std;
int remain[6];
int n=10;
int a[11][11];
int answer = 987654321;
bool canput(int x, int y, int k){
    if(x+k>10 || y+k>10) return false;
    if(remain[k] <=0) return false;
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            if(a[x+i][y+j] == 0) return false;
        }
    }
    return true;
}
void solve(int x, int y, int cnt){
    if(x ==10 && y ==0){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(a[i][j] == 1) return;
            }
        }
        answer= min(answer, cnt);
        return ;
    }
    int nx = x;
    int ny = y+1;
    if(ny == 10){
        nx+=1;
        ny=0;
    }
    if(a[x][y] ==1){
        for(int k=1; k<=5; k++){
            if(canput(x,y,k)){
                remain[k]-=1;
                for(int i=0; i<k; i++){
                    for(int j=0; j<k; j++){
                        a[x+i][y+j] = 0;
                    }
                }
                solve(nx,ny,cnt+1);
                remain[k]+=1;
                for(int i=0; i<k; i++){
                    for(int j=0; j<k; j++){
                        a[x+i][y+j] = 1;
                    }
                }
            }
            
        }
    }
    else solve(nx,ny,cnt);

}
int main(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i=1; i<=5; i++){
        remain[i] = 5;
    }
   solve(0,0,0);
   if(answer == 987654321) printf("-1\n");
   else printf("%d\n", answer);
   return 0;
}