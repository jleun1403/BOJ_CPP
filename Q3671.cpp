#include <bits/stdc++.h>
using namespace std;
bool prime[10000000];
bool d[10000000];
bool check[10000000];
int solve(string s){
    int ans = 0;
    sort(s.begin(), s.end());
    do{
        for(int i=0; i<s.size(); i++){
            for(int j=i+1; j<=s.size(); j++){
                int n = stoi(s.substr(i,j));
                if(prime[n] == 0 && check[n] == false){
                   check[n] = true;
                   // printf("%d\n", n);
                    ans +=1;
                }
            }
        }
    }while(next_permutation(s.begin(),s.end()));
    return ans;
}
int main(){
    int t;
    cin >>t;
    prime[1] = 1;
    prime[0] = 1;
    for(int i=2; i*i <10000000; i++){
        if(!prime[i]){
            for(int j=i*2; j<=10000000; j+=i){
                prime[j]= true;
            }
        }
    }
    string s;
    while(t--){
        cin >> s;
        memset(check,false, sizeof(check));
        printf("%d\n",solve(s));
    }
    return 0;
}