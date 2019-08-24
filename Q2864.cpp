#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int maxnum =0;
    int minnum =0;
    string sa = to_string(a);
    string sb = to_string(b);
    string temp = "";
    for(int i=0; i<sa.size(); i++){
        if(sa[i] == '5') {
            sa[i] = '6';
        }
        temp += sa[i];
    }
    maxnum += stoi(temp);
    
    temp ="";
    for(int i=0; i<sb.size(); i++){
        if(sb[i] == '5') sb[i] ='6';
        temp += sb[i];
    }
    maxnum += stoi(temp);
    
    sa = to_string(a);
    sb = to_string(b);
    temp ="";
    for(int i=0; i<sa.size(); i++){
        if(sa[i]=='6') sa[i] ='5';
        temp+= sa[i];
       
    }
    minnum += stoi(temp);
    temp ="";
    for(int i=0 ; i<sb.size(); i++){
        if(sb[i] == '6') sb[i] = '5';
        temp +=sb[i];
    }
    minnum += stoi(temp);
    printf("%d %d\n", minnum, maxnum);
    return 0;

    
    

}