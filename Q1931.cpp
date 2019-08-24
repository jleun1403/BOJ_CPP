#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main(){
    int n;
    cin >> n;
    stack<pair<int ,int >>s;
    vector<pair<int, int>> v;
    for (int i = 0 ; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), cmp);
    s.push(v[0]);
    for (int i = 1 ; i < n ; i++) {
        if (v[i].first >= s.top().second)
            s.push(v[i]);
    }
    cout << s.size();
}





