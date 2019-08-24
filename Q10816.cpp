#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    int m, n;
    scanf("%d", &m);
    vector<int> v(20000005);
    int number;
    for (int i = 0 ; i < m ; i++) {
        scanf("%d", &number);
        v[number + 10000000]++;
    }
    scanf("%d", &n);

    for (int i = 0 ; i < n ; i++) {
        int x;
        scanf("%d", &x);
        cout << v[x + 10000000] << ' ';
    }

}
