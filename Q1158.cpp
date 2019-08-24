#include <list>
#include <iostream>

using namespace std;

int main(){
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    list<int> l;
    for (int i = 0 ; i < n ; i++)
        l.push_back(i+1);
    auto a = l.end();
    a--;
    cout << '<';
    while(l.size() > 1) {
        auto temp = a;
        for (int i = 1 ; i < m ; i++) {
            temp++;
            if (temp == l.end())
                temp = l.begin();
        }
        a = temp++;
        if (temp == l.end())
            temp = l.begin();
        cout << *temp<< ','<< ' ';
        l.erase(temp);
    }
    cout << l.front() << '>';
}
