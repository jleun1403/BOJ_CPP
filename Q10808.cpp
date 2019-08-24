#include <iostream>
#include <vector>
using namespace std;

int main(){
    string s;
    vector<int> v(26);
    cin >> s;
    for (int i = 0 ; i < s.length() ; i++){
        v[s[i] - 97]++;
    }
    for (int i = 0 ; i < 26 ; i++) {
        cout << v[i] <<' ';
    }
}
