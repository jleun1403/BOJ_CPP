#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, k;
int answer ;
struct SHARK{
    int r,c,s,d,z, death;
};
SHARK arr[101*101];
int a[101][101];
int main(){
    cin >> n>> m>> k;
    for(int i=1; i<=k; i++){
       cin >> arr[i].r >> arr[i].c >> arr[i].s >> arr[i].d >> arr[i].z;
       arr[i].r-=1;
       arr[i].c-=1;
       a[arr[i].r][arr[i].c] = i; 
    }
    for(int t=0; t<m; t++){
        for(int x =0; x<n; x++){
            if(a[x][t] != 0){
                arr[a[x][t]].death = 1;
                answer += arr[a[x][t]].z;
                //cout << "t = " << t << ' '<< arr[a[x][t]].z << '\n';
                a[x][t] = 0;
                break;
            }
        }
        int temp[101][101];
        memset(temp, 0, sizeof(temp));
        for(int i=1; i<=k; i++){
            if(arr[i].death == 1) continue;
            int x = arr[i].r;
            int y = arr[i].c;
            int s = arr[i].s;
            int dir = arr[i].d;
            int nx, ny;
            while(true){
                nx = x + s * dx[dir-1];
                ny = y + s * dy[dir-1];
                if(nx >=0 && nx <n && ny >=0 && ny <m) break;
                if(dir == 1 && nx <0)  s-= x, x = 0, dir = 2;
                else if (dir ==2 && nx >= n) s-= n-1 -x, x = n-1, dir =1;
                else if(dir == 3 && ny >=m) s-= m-1-y, y = m-1, dir = 4;
                else if (dir == 4 && ny <0)  s-=y, y = 0 ,dir = 3;                   
            }
            if(temp[nx][ny] !=0){
                if(arr[temp[nx][ny]].z  < arr[i].z){
                    arr[temp[nx][ny]].death = 1; temp[nx][ny] = i;
                }
                else arr[i].death = 1;
            }
            else temp[nx][ny] = i;
            arr[i].r = nx, arr[i].c = ny, arr[i].d = dir;
        }
        for(int p=0; p<n; p++){
            for(int q=0; q<m; q++){
                a[p][q] = temp[p][q];
            }
        }
    }
    cout << answer << '\n';
    return 0;
}