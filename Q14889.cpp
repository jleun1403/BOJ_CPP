#include <bits/stdc++.h>
using namespace std;
int n;
int a[21][21];
int ans = 987654321;
vector <int> s1;
vector <int> s2;
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0 ;j<n ;j++){
            cin >> a[i][j];
        }
    }
    vector <int> v;
    for(int i=0; i< n/2; i++){
        v.push_back(0);
        v.push_back(1);
    }
    sort(v.begin(), v.end());
    do{
        s1.clear();
        s2.clear();
        for(int i=0; i<v.size(); i++){
            if(v[i] == 1){
                s1.push_back(i);
            }
            else {
                s2.push_back(i);
            }
        }
        long long sum1= 0;
        long long sum2= 0;
        for(int i=0; i<n/2-1; i++){
            for(int j=i+1; j<n/2; j++){
                sum1 += a[s1[i]][s1[j]];
                sum1 += a[s1[j]][s1[i]];
                sum2 += a[s2[i]][s2[j]];
                sum2 += a[s2[j]][s2[i]];
            }
        }
        int sum = abs(sum1- sum2);
        ans = min(ans, sum);
    }while(next_permutation(v.begin(), v.end()));
    cout << ans << '\n';
    return 0;
}