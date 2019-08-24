#include <deque>
#include <iostream>

using namespace std;

int main()
{
    deque<int> v;
    string command;
    int testcase;
    int enter;
    scanf("%d", &testcase);
    while(testcase--)
    {
        cin >>command;
        if (command == "push")
        {
            scanf("%d", &enter);
            v.push_back(enter);
        }
        else if (command == "pop")
        {
            scanf("%d", &enter);
            if (!v.empty())
            {
                cout << v.front() << '\n';
                v.pop_front();
            }
            else
                cout << "-1" << '\n';
        }
        else if (command == "size")
        {
            cout << v.size() << '\n';
        }
        else if (command == "front")
        {
            if (!v.empty())
            {
                cout << v.front() << '\n';
            }
            else
                cout << "-1" << '\n';
        }
        else if (command == "back"){
                if (!v.empty())
            {
                cout << v.back() << '\n';
            }
            else
                cout << "-1" << '\n';
        }
        else if (command == "empty") {
            cout << v.empty() << '\n';
        }
    }
}
