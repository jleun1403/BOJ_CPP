#include <bits/stdc++.h>
using namespace std;
int n, low, high;
int a[51][51];
int d[51][51];
int d_copy[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int sum, number;
int change[2501];
void dfs(int x, int y, int cnt)
{
    d[x][y] = cnt;
    sum += a[x][y];
    number += 1;
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
        {
            if (d[nx][ny] == 0 && abs(a[nx][ny] - a[x][y]) >= low && abs(a[nx][ny] - a[x][y]) <= high)
            {
                dfs(nx, ny, cnt);
            }
        }
    }
}
void solve(int x, int y, int cnt)
{
    d_copy[x][y] = cnt;
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
        {
            if (d_copy[nx][ny] == 0 && abs(a[nx][ny] - a[x][y]) >= low && abs(a[nx][ny] - a[x][y]) <= high)
            {
                dfs(nx, ny, cnt);
            }
        }
    }
}
int main()
{
    scanf("%d %d %d", &n, &low, &high);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int ans = 0;
    int cnt = 0;
    int s_cnt = 0;
    while (true)
    {
        cnt = 0;
        s_cnt = 0;
        memset(d, 0, sizeof(d));
        memset(d_copy, 0, sizeof(d_copy));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (d[i][j] == 0)
                {
                    sum = 0;
                    number = 0;
                    cnt++;
                    dfs(i, j, cnt);
                    change[cnt] = sum / number;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = change[d[i][j]];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (d_copy[i][j] == 0)
                {
                    s_cnt++;
                    solve(i, j, s_cnt);
                }
            }
        }
        
        if (cnt == s_cnt)
        {
           
            cout << ans << '\n';
             break;
            return 0;
        }
        ans += 1;
    }
}