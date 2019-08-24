#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int a[101][101];
int d[101][101];

int n, m;

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++){
    
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }
    memset(d, -1, sizeof(d));

    queue<pair<int, int>> q;
    queue<pair<int, int>> next_queue;
    q.push(make_pair(0, 0));
    d[0][0] = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (d[nx][ny] == -1)
                {
                    if (a[nx][ny] == 0)
                    {
                        d[nx][ny] = d[x][y];
                        q.push(make_pair(nx, ny));
                    }
                    else
                    {
                        d[nx][ny] = d[x][y] + 1;
                        next_queue.push(make_pair(nx, ny));
                    }
                }
            }
        }
        if (q.empty())
        {
            q = next_queue;
            next_queue = queue<pair<int,int>> ();
        }
    }
    cout << d[n - 1][m - 1] << '\n';
    return 0;
}