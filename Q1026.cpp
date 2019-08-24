#include <bits/stdc++.h>
using namespace std;
vector <int> a;
vector <pair<int,int>> b;
int main(){
    int n, x, sum;
    cin >> n;
    sum = 0;
    for(int i=0; i<n; i++){
        scanf("%d", &x);
        a.push_back(-x);
    }
    for(int i=0; i<n; i++){
        scanf("%d", &x);
        b.push_back(make_pair(x, i));
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i=0; i<b.size(); i++){
        b[i].second = i;
    }
    for(int i=0; i<n; i++){
        sum += -a[i] * b[i].first;
    }
    cout << sum << '\n';
    return 0;
}