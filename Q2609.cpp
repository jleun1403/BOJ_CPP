#include <iostream>
#include <vector>

using namespace std;
int gcd(int a, int b){
    if (a == 1 || b == 1)
        return 1;
    int c = min(a, b);
    int d = max(a, b);
    for (int i = c ; i > 0 ; i--){
        if (d % i == 0 && c % i == 0)
            return i;
    }
    return 1;
}

int main(){

    int testcase;
    cin >> testcase;
    while(testcase--) {
        long long sum = 0L;
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0 ; i <n ; i++){
            int k;
            cin >> k;
            v[i] = k;
        }
        for (int i = 0 ; i < n - 1 ; i++) {
            for (int j = i+1; j < n; j++){
                sum = sum + gcd(v[i], v[j]);
            }
        }
        cout << sum <<'\n';

    }
}
