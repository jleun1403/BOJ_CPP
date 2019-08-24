#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d\n", &n);
    for (int i = 0 ; i < n ; i++) {
        string s;
        getline(cin, s);
        if ('a' <= s[0] && s[0] <= 'z') {
            s[0] = s[0] - 'a' + 'A';
        }
        cout << s << '\n';
    }
    return 0;
}









