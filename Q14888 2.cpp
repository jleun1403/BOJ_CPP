#include <bits/stdc++.h>
using namespace std;
int a[12];
vector<int> v;
long long maxnum = -1e18;
long long minnum = 1e18;
int main(){
    int n;
    cin >>n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=4; i++){
        int x;
        cin >> x;
        for(int j=0; j<x; j++){
            v.push_back(i);
        }
    }
    sort(v.begin(),v.end());
    do{
        long long sum = a[0];
        for(int i=0; i<v.size(); i++){
            if(v[i]==1){
                sum+=a[i+1];
            }
            else if(v[i]==2){
                sum-=a[i+1];
            }
            else if( v[i] == 3){
                sum*=a[i+1];
            }
            else if(v[i] == 4){
                sum/=a[i+1];
            }
        }
        maxnum = max(maxnum, sum);
        minnum = min(minnum, sum);
    }while(next_permutation(v.begin(),v.end()));
    cout << maxnum << '\n';
    cout << minnum << '\n';
    return 0;
}