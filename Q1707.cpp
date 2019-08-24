#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> v;
vector<int> group;


int main()
{
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> checked(n+1, 0);
        group.resize(n+1, 0);
        v.resize(n+1);
        queue<int> q;
        for (int i = 0 ; i < m ; i++)
        {
            int from;
            int to;
            cin >> from >>to;
            v[from].push_back(to);
            v[to].push_back(from);
        }

        bool flag = true;
        for (int i = 1; i<=n ; i++) {
            if (checked[i] == 0) {
        q.push(i);
        checked[i] = 1;
        group[i] = 1;
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0 ; i < v[x].size(); i++)
            {
                if (group[x] == 1 && group[v[x][i]] == 1)
                    flag = false;
                else if (group[x] == 2 && group[v[x][i]] == 2)
                    flag = false;
                if (checked[v[x][i]] == 0)
                {
                    checked[v[x][i]] = 1;
                    if (group[x] == 1)
                        group[v[x][i]] = 2;
                    else
                        group[v[x][i]] = 1;
                    q.push(v[x][i]);
                }
            }
        }
            }
        }
        if (flag)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';

        v.clear();
        checked.clear();
        group.clear();


    }
}
