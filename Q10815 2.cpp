#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    int m, n;
    scanf("%d", &m);
    vector<int> v;
    int number;
    for (int i = 0 ; i < m ; i++) {
        scanf("%d", &number);
        v.push_back(number);
    }
    sort(v.begin(), v.end());
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        int x;
        scanf("%d", &x);
        if (binary_search(v.begin(), v.end(), x))
            cout << binary_search(v.begin(), v.end(), x) << ' ';
        else
            cout << "0" << ' ';
    }

}
