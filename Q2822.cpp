#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int main(){
    int sum = 0;
    int a;
    for(int i=1; i<=8; i++){
        scanf("%d", &a);
        v.push_back(make_pair(a,i));
    }
    sort(v.begin(), v.end());
    vector<int> num;
    for(int i=v.size()-1; i>=v.size()-5; i--){
        sum+=v[i].first;
        num.push_back(v[i].second);
    }
    printf("%d\n", sum);
    sort(num.begin(), num.end());
    for(int i=0; i<num.size(); i++){
        printf("%d ", num[i]);
    }
    return 0;

}