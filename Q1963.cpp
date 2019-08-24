#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>

using namespace std;
bool isPrime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    for (int i = 2 ; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    while(testcase--) {
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        if (t1 == t2) {
            cout << 0 << '\n';
            continue;
        }
        if (isPrime(t1) == false || isPrime(t2) == false) {
            cout << "Impossible" << '\n';
            continue;
        }
        bitset<10000> b;
        bitset<10000> temp;
        b.set(t1);
        int i;
        for (i = 1 ; i < 1000 ; i++) {
            temp = b;
            for (int j = 1000 ; j < 10000 ; j++) {
                if (temp[j] == 1) {
                    for (int k = 0 ; k < 10 ; k++) {
                        if (isPrime((j / 10) * 10 + k))
                            b.set((j/10) * 10 + k);
                    }
                    for (int k = 0 ; k < 10 ; k++) {
                        if (isPrime((j/100) * 100 + k * 10 + (j%10)))
                            b.set((j/100) * 100 + k * 10 + (j%10));
                    }
                    for (int k = 0 ; k < 10 ; k++) {
                        if (isPrime((j/1000) * 1000 + k * 100 + (j % 100)))
                            b.set((j/1000) * 1000 + k * 100 + (j % 100));
                    }
                    for (int k = 1 ; k < 10 ; k++) {
                        if (isPrime( k * 1000 + (j % 1000)))
                            b.set( k * 1000 + (j % 1000));
                    }
                }
            }
            if (b[t2] == 1) {
                cout << i << '\n';
                b.reset();
                temp.reset();
                break;
            }
        }
    }







  return 0;
}
