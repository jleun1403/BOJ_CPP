#include <iostream>
using namespace std;

int main(){
    string s;
    int number = 0;
    cin >> s;
    for (int i = 0 ; i < s.length() ; i++) {
        if (s[i] == ',')
            number++;
    }
    cout <<number +1 ;
}
