#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
    int n;
    long long m;
    cin >> n>> m;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    int left =1, right=2, leng =0;
    long long sum = (long long)a[1];
    bool ok = false;
    vector <int> v;
    while(left <=right && right <=n+1){
        
        if(sum >=m){
            ok = true;
            v.push_back(right - left);
            sum -= a[left];
            left+=1;
        }
        else {
            if(right ==n+1) break;
            sum +=a[right];
            right +=1;
        }
    }
    
    if(ok == false){
        cout << "0\n";
    }
    else {
        sort(v.begin(), v.end());
        cout << v[0]<< '\n';
    }
    return 0;
}