#include <iostream>
using namespace std;

int main(){
    int counts = 1;
    string s;
    getline(cin, s);
    if (s.length() == 0) {
        cout << 0;
        return 0;
    }
    else if (s.length()== 1){
        if (s[0] == ' ')
            counts = 0;
        else
            counts = 1;
        cout <<counts;
        return 0;
    }
    for (int i = 0 ; i < s.length() - 2; i++){
        if ((s[i] != ' ') && (s[i+1] == ' ') && (s[i+2] != ' '))
            counts++;
    }
    cout <<counts;
}
