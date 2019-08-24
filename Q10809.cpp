#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<int> v(26, -1);
    string s;
    cin >> s;
    for (int i = s.length() -1 ; i >= 0 ; i--){
        v[s[i] - 97] = (i);
    }
    for (int i = 0 ; i <26 ; i++)
        cout << v[i] << ' ';


    return 0;
}
