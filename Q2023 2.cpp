#include <bits/stdc++.h>

using namespace std;

int n;
bool isprime(long long x) {
    if (x <= 1) return false;
    if (x == 2) return true;
    for (long long i = 2 ; i * i <= x ; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

void go(int digit, string made) {
    if (digit == n) {
        cout << made << '\n';
        return;
    }
    for (int i = 0 ; i <= 9 ; i++) {
        string temp = made + to_string(i);
        if (isprime(stoll(temp))) {
            go(digit + 1, temp);
        }
    }
}

int main() {
    cin >> n;
    go(0, "");
    return 0;
}