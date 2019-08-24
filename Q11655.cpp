#include <iostream>

using namespace std;

int main(){
    string a = "abcdefghijklmnopqrstuvwxyz";
    string b = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s;
    getline(cin, s);
    for (int i = 0 ; i < s.length() ; i++){
        if (s[i] >= 65 && s[i] <= 90)
            s[i] = (s[i] -52) % 26 +65;
        else if (s[i] >= 97 && s[i] <= 122)
            s[i] = (s[i] - 84) % 26 + 97;
    }
    cout << s ;
}
