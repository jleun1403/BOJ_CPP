#include <bits/stdc++.h>

using namespace std;

int weight[26];

int main() {
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        int mul = 1;
        for (int j = s.length()-1 ; j >= 0 ; j--) {
            weight[s[j] - 'A'] += mul;
            mul *= 10;
        }
    }

    sort(weight, weight + 26);
    reverse(weight, weight + 26);

    long long answer = 0;
    long long mul = 9;
    for (int i = 0 ; i < 26 ; i++) {
        answer += weight[i] * mul;
        mul -= 1;
    }
    printf("%lld\n", answer);
    return 0;
}