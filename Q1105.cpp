#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string s1, s2;
    cin >>s1 >> s2;
    if (s1.length() != s2.length())
        printf("0");
    else {
        int ans = 0;
        for (int i = 0 ; i < s1.length() ; i++) {
            if (s1[i] == s2[i] && s2[i] == '8')
                ans++;
            else if (s1[i] != s2[i])
                break;
        }
        printf("%d", ans);
    }















  return 0;
}
