#include <iostream>
#include <vector>

using namespace std;

int main() {
    int stairs;
    cin >> stairs;
    vector<vector<int>> D(stairs + 1, vector<int>(3));
    vector<int> a(stairs + 1);

    a[0] = 0;
    for (int i = 1 ; i <= stairs ; i++){
        int k;
        cin >> k;
        a[i] = k;
    }
    D[0] = {0, 0, 0};
    D[1] = {a[1], a[1], 0};
    for (int i = 2 ; i <= stairs ; i++) {
        D[i][1] = max(D[i-2][1], D[i-2][2]) + a[i];
        D[i][2] = D[i-1][1] + a[i];
    }
    cout << max(D[stairs][1], D[stairs][2]);
}
