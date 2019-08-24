#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1);
    for (int i = 0 ; i <= n ; i++) {
        v[i] = i;
    }
    auto a = v.begin();
    auto b = a;
    auto c = a;
    for (int i = 0 ; i < m ; i++) {
        int start;
        int to;
        int mid;
        cin >>start >>to >> mid;
        a = v.begin() + start;
        b = v.begin() + to;
        c = v.begin() + mid;
        rotate(a, c, b+1);

    }
    for (int i = 1 ; i <= n ; i++) {
        cout <<v[i] << ' ';
    }

}
