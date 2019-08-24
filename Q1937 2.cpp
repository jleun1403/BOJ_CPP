#include <bits/stdc++.h>
using namespace std;

int arr[501][501];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, - 1, 1};
int n;
int d[501][501];

int dfs(int x, int y)
{
    if(d[x][y] !=0) return d[x][y];
    d[x][y] =1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
        {
            if (arr[nx][ny] > arr[x][y])
            
                 d[x][y] = max(d[x][y], dfs(nx,ny) +1 );
            
        }
    }
   return d[x][y];
}
int main()
{
    cin >> n;
    //memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
             ans = max(ans,dfs(i, j));
        }
    }
    /*for(int i=0; i<n; i++){
        for(int j=0; j<n ; j++){
            ans = max(ans, d[i][j]);
        }
     
    }
    
   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           cout << d[i][j] << ' ';
       }
       cout << '\n';
   }
   */
    
    cout << ans << '\n';
    return 0;
}