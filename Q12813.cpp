#include <iostream>

using namespace std;

void c1(string s1, string s2){
    for (int i = 0 ; i < s1.length() ; i++) {
        if (s1[i] == '1' && s2[i] == '1')
            cout << 1;
        else
            cout <<0;
    }
    cout <<'\n';
}
void c2(string s1, string s2){
    for (int i = 0 ; i < s1.length() ; i++) {
        if (s1[i] == '1' || s2[i] == '1')
            cout << 1;
        else
            cout <<0;
    }
    cout <<'\n';
}

void c3(string s1, string s2){
    for (int i = 0 ; i < s1.length() ; i++) {
        if ((s1[i] == '1' && s2[i] == '0') || ((s1[i] == '0' && s2[i] == '1')))
            cout << 1;
        else
            cout <<0;
    }
    cout <<'\n';
}
void c4(string s1){
    for (int i = 0 ; i < s1.length() ; i++) {
        if ((s1[i] == '0'))
            cout << 1;
        else
            cout <<0;
    }
    cout <<'\n';
}


int main(){
    string s1, s2;
    cin >> s1;
    cin >> s2;
    c1(s1, s2);
    c2(s1, s2);
    c3(s1, s2);
    c4(s1);
    c4(s2);
}
