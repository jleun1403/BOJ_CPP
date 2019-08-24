#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    char op, non;
    cin >> a;
    scanf("%c", &non);
    scanf("%c", &op);
    //cout << '\n';
    cin >> b;
    if(a.size() >=b.size()){
        swap(a,b);
    }
    if(op == '+'){
        if(a.size() == b.size()) {
            string s = "2";
            for(int i=0; i<a.size()-1; i++){
                s +="0";
            }
            cout << s << '\n'; 
        }
        else{
            b[b.size()-a.size()] = '1';
            cout << b << '\n';
        }
    }
    else{
        string s= "1";
        for(int i=0; i<a.size()-1 + b.size()-1; i++){
            s+="0";
        }
        cout << s << '\n';
    }
    return 0;
}