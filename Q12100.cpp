#include <bits/stdc++.h>
using namespace std;
int n;
int a[21][21];
int ans;
//vector<int> path;
int path[6];

int solve()
{
    int b[21][21];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = a[i][j];
        }
    }

    for (int k = 0; k < 5; k++)
    {
        if (path[k] == 1)
        { //위로 밀기
            for (int j = 0; j < n; j++)
            {
                int it = 0;
                for (int i = 0; i < n; i++)
                {
                    if (b[i][j] != 0)
                    {
                        if (i == it)
                            it ++;
                        else
                        {
                            b[it][j] = b[i][j];
                            b[i][j] = 0;
                            it++;
                        }
                    }
                }
            }
            for (int j = 0; j < n; j++)
            { // 블록 합치기
                for (int i = 0; i < n - 1; i++)
                {
                    if (b[i][j] == b[i + 1][j])
                    {
                        b[i][j] *= 2;
                        b[i+1][j] = 0;
                    }
                }
            }
            for (int j = 0; j < n; j++)
            {
                int it = 0;
                for (int i = 0; i < n; i++)
                {
                    if (b[i][j] != 0)
                    {
                        if (i == it)
                            it ++;
                        else
                        {
                            b[it][j] = b[i][j];
                            b[i][j] = 0;
                            it ++;
                        }
                    }
                }
            }
        }
        else if (path[k] == 2)
        { // 아래로 밀기
            for (int j = 0; j < n; j++)
            {
                int it = n - 1;
                for (int i = n - 1; i >= 0; i--)
                {
                    if (b[i][j] != 0)
                    {
                        if (i == it)
                            it --;
                        else
                        {
                            b[it][j] = b[i][j];
                            b[i][j] = 0;
                            it --;
                        }
                    }
                }
            }
            for (int j = 0; j < n; j++)
            {
                for (int i = n - 1; i > 0; i--)
                {
                    if (b[i][j] == b[i - 1][j])
                    {
                        b[i][j] *= 2;
                        b[i - 1][j] = 0;
                    }
                }
            }
            for (int j = 0; j < n; j++)
            {
                int it = n - 1;
                for (int i = n - 1; i >= 0; i--)
                {
                    if (b[i][j] != 0)
                    {
                        if (i == it)
                            it --;
                        else
                        {
                            b[it][j] = b[i][j];
                            b[i][j] = 0;
                            it --;
                        }
                    }
                }
            }
        }
        else if (path[k] == 3)
        { // 왼쪽으로 밀기
            for (int i = 0; i < n; i++)
            {
                int it = 0;
                for (int j = 0; j < n; j++)
                {
                    if (b[i][j] != 0)
                    {
                        if (j == it)
                            it ++;
                        else
                        {
                            b[i][it] = b[i][j];
                            b[i][j] = 0;
                            it ++;
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    if (b[i][j] == b[i][j + 1])
                    {
                        b[i][j] *= 2;
                        b[i][j + 1] = 0;
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                int it = 0;
                for (int j = 0; j < n; j++)
                {
                    if (b[i][j] != 0)
                    {
                        if (j == it)
                            it ++;
                        else
                        {
                            b[i][it] = b[i][j];
                            b[i][j] = 0;
                            it ++;
                        }
                    }
                }
            }
        }
        else if (path[k] == 4)
        { // 오른쪽으로 밀기
            for (int i = 0; i < n; i++)
            {
                int it = n - 1;
                for (int j = n - 1; j >= 0; j--)
                {
                    if (b[i][j] != 0)
                    {
                        if (it == j)
                            it --;
                        else
                        {
                            b[i][it] = b[i][j];
                            b[i][j] = 0;
                            it --;
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = n - 1; j > 0; j--)
                {
                    if (b[i][j] == b[i][j - 1])
                    {
                        b[i][j] *= 2;
                        b[i][j - 1] = 0;
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                int it = n - 1;
                for (int j = n - 1; j >= 0; j--)
                {
                    if (b[i][j] != 0)
                    {
                        if (it == j)
                            it --;
                        else
                        {
                            b[i][it] = b[i][j];
                            b[i][j] = 0;
                            it --;
                        }
                    }
                }
            }
        }
    }
    int max_num = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            max_num = max(max_num, b[i][j]);
        }
    }
    return max_num;
}
void go(int cnt)
{
    if (cnt == 5)
    {
        ans = max(ans, solve());
        return;
    }
    for (int i = 1; i <= 4; i++)
    {
        //path.push_back(i);
        path[cnt] = i;
        go(cnt + 1);
        //path.pop_back();
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    go(0);
    cout << ans << '\n';
    return 0;
}