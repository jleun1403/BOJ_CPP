#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int main(){
    int a;
    for(int i=0; i<4; i++){
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int x = min(v[0],v[1]);
    int y = min(v[2],v[3]);
    cout << x*y<< '\n';
    return 0;
}