#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int main(){
    int n, m;
    cin >> n>> m;
    for(int i=1; i*i<=n; i++){
        if(n %i == 0){
            v.push_back(i);
            if( i*i !=n) v.push_back(n/i);
        }
    }
    sort(v.begin(), v.end());
    if(v.size() < m) cout << '0' << '\n';
    else cout << v[m-1] << '\n';
    return 0;
}