#include <bits/stdc++.h>
using namespace std;
int n;
int arr[501][501];
int ans;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0 - 1, 1};
bool check[501][501];
int d[501][501];
int bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    int cnt = 1;
    d[i][j] = cnt;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (check[nx][ny] == false && arr[nx][ny] > arr[x][y])
                {
                    d[nx][ny] = d[x][y] +1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cnt;
            cnt = bfs(i, j);
            ans = max(ans, cnt);
        }
    }
}