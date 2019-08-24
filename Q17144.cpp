#include <bits/stdc++.h>
using namespace std;
int n, m, t;
int a[51][51];
int a_copy[51][51];
int dx[4]= {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool check[51][51];
void move1(int p, int q){
    int x = p;
    int y = q;
    int temp1, temp2, temp3;
    temp1 = a[x][m-1];
    temp2 = a[0][m-1];
    temp3 = a[0][0];
    for(int i= m-1; i >=y+2; i--){
        a[x][i] = a[x][i-1];
    }
    for(int i= 0; i<=x-1; i++){
        a[i][m-1] = a[i+1][m-1];
    }
    a[x-1][m-1] = temp1;
        
    for(int i = 0; i<m-2; i++){
        a[0][i] = a[0][i+1];
    }
    a[0][m-2] = temp2;
    
    for(int i= x-1; i>=1; i--){
        a[i][0] = a[i-1][0];
    }
    a[1][0] = temp3;
    a[x][y+1] = 0;
}
void move2(int i, int j){
    int x = i;
    int y = j;
    int temp1, temp2, temp3;
    temp1= a[x][m-1];
    temp2= a[n-1][m-1];
    temp3= a[n-1][0];
    for(int i=m-1; i>=y+2; i--){
        a[x][i] = a[x][i-1];
    }
    for(int i =n-1; i>=x+2; i--){
        a[i][m-1] = a[i-1][m-1];
    }
    a[x+1][m-1] = temp1;
    for(int i=0; i<m-2; i++){
        a[n-1][i] = a[n-1][i+1];
    }
    a[n-1][m-2] = temp2;
    for(int i= x+1; i< n-2 ; i++){
        a[i][0] = a[i+1][0];
    }
    a[n-2][0] = temp3;
    a[x][y+1] = 0;
}
int main(){
    scanf("%d %d %d", &n, &m, &t);
    int x_1, y_1, x_2, y_2;
    int answer = 0;
    bool ok = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] == -1 && ok == false){
                ok = true;
                x_1 = i, y_1 = j;
            }
            else if(a[i][j] == -1 && ok == true){
                x_2 = i, y_2 = j;
            }

        }
    }
    for(int tt =0; tt<t; tt++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                a_copy[i][j] = a[i][j];
            }
        }
        queue <pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] >=5){
                    q.push(make_pair(i,j));
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && nx<n && ny >=0 && ny <m && a_copy[nx][ny]!=-1){
                    a_copy[nx][ny] += a[x][y]/5;
                    a_copy[x][y] -= a[x][y]/5;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                a[i][j] = a_copy[i][j];
            }
        }
        move1(x_1, y_1);
        move2(x_2, y_2);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] >=0){
                answer += a[i][j];
            }
        }
    }

    printf("%d\n", answer);
    return 0;

}