#include <iostream>
#include <stack>
#include <vector>

using namespace std;
bool possible(stack<int> v, int n, vector<int> arrays)
{
    int i = 1;
    int p = 0;
    v.push(0);
    while (true)
    {
        if (p > n)
            return false;
        if (i == n+2)
        {
            return false;
        }
        if (i == n+1 && v.top() == 0)
        {
            break;
        }
        int target;
        target = arrays[p++];
        if (target > v.top())
        {
            while(target > v.top())
            {
                v.push(i++);
            }
        }
        if (target < v.top())
        {
            while(target > v.top())
            {
                v.pop();
            }
        }
        if (target == v.top())
        {
            v.pop();
        }
    }
    return true;
}

int main()
{
    stack<int> v;
    int n;
    vector<int> arrays;
    scanf("%d", &n);
    int i = 1;
    int p = 0;
    v.push(0);
    for (int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        arrays.push_back(a);
    }
    if (!possible(v, n, arrays)){
        cout <<"NO";
        return 0;
    }
    while (true)
    {
        if (i == n+2)
        {
            cout <<"NO";
        }
        if (i == n+1 && v.top() == 0)
        {
            break;
        }
        int target;
        target = arrays[p++];
        if (target > v.top())
        {
            while(target > v.top())
            {
                v.push(i++);
                cout <<"+" <<'\n';
            }
        }
        if (target < v.top())
        {
            while(target > v.top())
            {
                v.pop();
                cout <<"-" <<'\n';
            }
        }
        if (target == v.top())
        {
            v.pop();
            cout <<"-" <<'\n';
        }


    }
    return 0;
}
