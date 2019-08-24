#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    vector<int> v(n + 1, 0);
    for (int i = 0 ; i < m ; i++) {
        int from;
        int to;
        int number;
        cin >> from >> to >>number;
        for (int j = from ; j <= to ; j++)
            v[j] = number;

    }
    for (int i = 1 ; i <= n ; i++)
        cout << v[i] << ' ';
    return 0;
}
