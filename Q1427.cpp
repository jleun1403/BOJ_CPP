#include <bits/stdc++.h>
using namespace std;
vector<int>v;
int main(){
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        v.push_back(s[i]-'0');
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1; i>=0; i--){
        cout << v[i];
    }
    return 0;
}