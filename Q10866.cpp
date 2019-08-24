#include <deque>
#include <iostream>

using namespace std;

int main(){
    deque<int> d;
    int testcase;
    int X;
    string command;
    cin >>testcase;
    while(testcase--){
        cin >>command;
        if (command == "push_back"){
            cin >> X;
            d.push_back(X);
        }
        else if (command == "push_front") {
            cin >> X;
            d.push_front(X);
        }
        else if (command == "pop_front") {
            if (d.empty())
                cout << "-1" << '\n';
            else{
                X = d.front();
                d.pop_front();
                printf("%d\n", X);
            }
        }
        else if (command == "pop_back") {
            if (d.empty())
                cout << "-1" << '\n';
            else{
                X = d.back();
                d.pop_back();
                printf("%d\n", X);
            }
        }
        else if (command == "size")
            cout << d.size() << '\n';
        else if (command == "empty")
            cout << d.empty() << '\n';
        else if (command == "front") {
            if (d.empty())
                cout <<"-1" << '\n';
            else
                cout << d.front() << '\n';
        }
        else if (command == "back"){
            if (d.empty())
                cout <<"-1" << '\n';
            else
                cout << d.back() << '\n';
        }
    }

}
