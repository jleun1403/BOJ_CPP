#include <bits/stdc++.h>
using namespace std;
int a[27];
vector <pair<int,int>> v(26);
int main(){
    string s;
    cin >> s;
    for(int i=0; i<s.size() ; i++){
        if(s[i]>='a' && s[i] <='z'){
            a[s[i]-'a'] +=1;
        }
        else if(s[i]>='A' && s[i]<='Z'){
            a[s[i]-'A'] +=1;
        }
    }
    for(int i=0; i<26; i++){
        v[i] = make_pair(a[i], i);
    }
    sort(v.begin(), v.end());
    if(v[25].first == v[24].first) printf("?\n");
    else printf("%c\n", v[25].second +'A');
    
    return 0;

}
