#include <bits/stdc++.h>
using namespace std;
vector<int> v[301];
int main(){
    int n, m;
    cin >> n>> m;
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        for(int j=0; j<m; j++){
            int x;
            scanf("%d", &x);
            v[a].push_back(x);
        }
    }
}