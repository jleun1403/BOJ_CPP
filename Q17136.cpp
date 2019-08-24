#include <bits/stdc++.h>
using namespace std;
int answer;
int n= 10;
int a[11][11];
int remain[6] ;
bool canput(int x, int y, int papersize){
    if(x+papersize > 10 || y+papersize >10) return false;
    if(remain[papersize] <=0) return false;
    for(int i=0; i<papersize; i++){
        for(int j=0; j<papersize; j++){
            if(a[x+i][y+j] == 0) return false;
        }
    }
    return true;
}
void go(int x, int y, int cnt){
    if(x == 10 && y == 0){
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                if(a[i][j]) {return ;}
            }
        }
        answer= min(answer, cnt);
        return ;
    }
    int nx = x;
    int ny = y+1;
    if(y == 9){
        nx = x+1;
        ny = 0;
    }
    if(a[x][y] ==1){
        for(int s=1; s<=5; s++){
            if(canput(x,y,s)){
                remain[s]-=1;
                for(int i=0; i<s; i++){
                    for(int j=0; j<s; j++){
                        a[x+i][y+j] = 0;

                    }
                }
                go(nx,ny,cnt+1);
                remain[s] +=1;
                for(int i=0; i<s; i++){
                    for(int j =0; j<s; j++){
                        a[x+i][y+j] =1;
                    }
                }
            }
        }
    }
    else{
        go(nx ,ny, cnt);
    }

}
int main(){
    answer= 987654321;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=5; i++){
        remain[i] = 5;
    }
    go(0,0,0);
    if(answer == 987654321) cout << "-1\n";
    else cout << answer <<'\n';
    return 0;
}