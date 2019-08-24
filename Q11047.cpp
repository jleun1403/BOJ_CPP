#include <iostream>
using namespace std;

int coin[10];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &coin[i]);
    }
    int cnt = 0;
    while (k != 0) {
        int i;
        for (i = n-1 ; i >= 0 ; i--){
            if (coin[i] <= k)
                break;
        }
        k = k - coin[i];
        cnt++;
    }
    cout << cnt;
}
