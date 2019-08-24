#include <bits/stdc++.h>
using namespace std;
int a[27];
int main(){
    int n;
    cin >>n ;
    string s;
    for(int i=0; i<n; i++){
        cin >> s;
        a[s[0]-'a'] +=1;
    }
    bool ok = false;
    for(int i=0; i<27; i++){
        if(a[i] >=5){
            ok =true;
            printf("%c", ('a'+ i));
        }
    }
    if(ok == false){
        printf("PREDAJA\n");
    }
    return 0;
}