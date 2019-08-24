#include <iostream>
#include <stack>

using namespace std;

int main(){
    string s;
    stack<char> v;
    cin >> s;
    int piece = 0;
    int slength = s.length();
    for (int i = 0 ; i < slength ; i++) {
        if (s[i] == '(')
                v.push(s[i]);
        else if (s[i] == ')'){
            if (s[i-1] == '('){
                v.pop();
                piece = piece + v.size();
            }
            else{
                v.pop();
                piece++;
            }
        }
    }
    cout << piece;

}
