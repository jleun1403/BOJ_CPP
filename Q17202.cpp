#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    string sum="";
    for(int i=0; i<a.size(); i++){
        sum+=a[i];
        sum+=b[i];
    }
    while(true){
        string temp = "";
        if(sum.size() == 2) break;
        for(int i=0; i<sum.size()-1; i++){
            temp += to_string(((sum[i]-'0') + (sum[i+1]-'0'))%10);
            
        }
        sum = temp;
    }
    cout << sum << '\n';
    return 0;
}