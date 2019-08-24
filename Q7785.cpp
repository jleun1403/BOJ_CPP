#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>

using namespace std;

int main() {
    set<string> s;
    int n;
    cin >>n;
    string name, what;
    for (int i = 0 ; i < n; i++) {
        cin >> name >> what;
        if (what == "enter")
            s.insert(name);
        else
            s.erase(s.find(name));
    }
    for (auto i = --s.end() ; i != --s.begin() ; i--) {
        cout << *i << '\n';
    }







  return 0;
}
