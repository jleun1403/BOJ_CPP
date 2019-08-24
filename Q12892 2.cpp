#include <bits/stdc++.h>
using namespace std;
vector <pair<long long,long long>> v;
int main(){
    int n;
    long long d;
    scanf("%d %lld", &n, &d);
    
    for(int i=0; i<n; i++){
        long long a, b;
        scanf("%lld %lld", &a, &b);
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end());
    long long answer= 0;
    int left = 0, right = 0;
    long long temp = 0;
    while(left <= right && right <n){
        if(v[right].first- v[left].first <d) {
            temp +=v[right].second;
            right+=1;
        }
        else {
            temp -= v[left].second;
            left +=1;
        }
        answer= max(answer, temp);
    }
    printf("%lld\n", answer);
}