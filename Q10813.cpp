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
    for (int i = 0 ; i < m ; i++) {
        int start;
        int to;
        cin >>start >>to;
        swap(v[start], v[to]);

    }
    for (int i = 1 ; i <= n ; i++) {
        cout <<v[i] << ' ';
    }

}
