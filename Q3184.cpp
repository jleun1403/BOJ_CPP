#include <bits/stdc++.h>
using namespace std;
char a[251][251];
int d[251][251];
int dx[4] = {-1 ,1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;
void dfs(int x, int y, int cnt){
    d[x][y] = cnt;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx <n && ny >=0 && ny <m){
            if(a[nx][ny] != '#' && d[nx][ny] == 0){
                dfs(nx,ny, cnt);
            }
        }
    }
}
int main(){
    cin >> n>> m;
    int numo = 0, numv = 0;
    for(int i=0; i<n; i++){
        for(int j=0 ; j<m; j++){
            scanf(" %c", &a[i][j]);
        }
    }
    int cnt = 0;
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] != '#' && d[i][j] == 0){
                cnt+=1;
                dfs(i,j,cnt);
            }
        }
    }
    /*for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }*/
    for(int k=1; k<=cnt; k++){
        int sum1=0, sum2 =0;
        for(int i=0; i<n; i++){
            for(int j=0 ; j<m; j++){
                if(d[i][j] == k){
                    if(a[i][j] == 'o') sum1+=1;
                    else if(a[i][j] == 'v') sum2+=1;
                }
            }
        }
        if(sum1>sum2) {
            numo +=sum1;
            numv +=0;
        }
        else{
            numo+=0;
            numv+=sum2;
        }
        //if(k == 3) cout << numo << ' '<< numv << '\n';
    }
    printf("%d %d\n", numo, numv);
    return 0;
}