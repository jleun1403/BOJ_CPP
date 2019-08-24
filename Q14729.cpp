#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int num[100001];

int main() {
    int n;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        int p;
        for (int k = 0 ; k < s.length() ; k++) {
            if (s[k] == '.')
                p = k;
        }
        s = s.substr(0, p) + s.substr(p+1);
        int k = stoi(s);
        num[k]++;
    }
    int p = 7;
    for (int i = 0 ; i <= 100000 ; i++) {
        if (num[i] <= p) {
            for (int k = 0 ; k < num[i] ; k++) {
                printf("%d.%03d\n", i / 1000 , i % 1000);
            }
            p -= num[i];
        }
        else {
            for (int k = 0 ; k < p ; k++){
                printf("%d.%03d\n", i / 1000 , i % 1000);
            }
            p = 0;
        }
    }
















  return 0;
}
