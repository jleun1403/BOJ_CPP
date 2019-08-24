#include <bits/stdc++.h>
using namespace std;
int a[50];
int main(){
    while(true){
        int n;
        cin >> n;
        if(n ==0 )break;
        memset(a, 0, sizeof(a));
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        vector<int>v;
        for(int i=0; i<6; i++){
            v.push_back(0);
        }
        for(int i=0; i<n-6; i++){
            v.push_back(1);
        }
        sort(v.begin(), v.end());
        do{
            for(int i=0; i<n; i++){
                if(v[i] == 0) cout << a[i] << ' ';
                else continue;
            }
            cout << '\n';
        }while(next_permutation(v.begin(),v.end()));
        cout << '\n';
    }
    return 0;
}