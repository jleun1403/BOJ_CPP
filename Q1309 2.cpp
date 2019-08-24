#include <bits/stdc++.h>
using namespace std;
int dist[100001];

int main(){
    int n;
    cin >> n;
    dist[1] = 3;
    dist[2] = 7;
    dist[3] = 17;
    dist[4] = 41;
    if(n >4){
        for(int i= 5; i<=n; i++){
            dist[i] = (dist[i-2] + dist[i-1]*2 ) %9901;
        }
    }
    cout << dist[n] << '\n';
    return 0;
}