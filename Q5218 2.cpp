#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    string s1, s2;
    while(t--){
        cin >>s1 >> s2 ;
        printf("Distances: ");
        for(int i=0; i<s1.size(); i++){
            
            if(s1[i] -'A' <= s2[i] - 'A') {
                printf("%d ", (s2[i]-'A')- (s1[i]-'A'));
            }
            else printf("%d ", 26-(s1[i]-'A') +(s2[i]-'A'));
        }
        printf("\n");
    }
    return 0;
}