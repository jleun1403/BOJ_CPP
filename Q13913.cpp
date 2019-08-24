#include <bits/stdc++.h>
using namespace std;
int d[100001];
int route[100001];
bool visited[100001];
queue <int> q;
int main(){
    int n, m;
    cin >> n>> m;
    d[n] = 0;
    q.push(n);
    visited[n] = true;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now -1 >= 0 && visited[now-1] == false) {
            d[now-1] = d[now] +1;
            visited[now-1] = true;
            route[now-1] = now;
            //if(now-1 == m) break;
            q.push(now-1);
        }
        if(now +1 <= 100000 && visited[now+1] == false){
            d[now+1] = d[now] + 1;
            visited[now+1] = true;
            route[now+1] = now;
            //if(now +1 == m) break;
            q.push(now+1);
        }
        if(now*2 <=100000 && visited[now*2] == false){
            d[now*2] = d[now];
            route[now*2] = now;
            visited[now*2] = true;
            //if(now*2 == m) break;
             q.push(now*2);
        }
    }
    printf("%d\n", d[m]);
    int k=n;
    while(k!=m){
        cout << k << ' ';
        k= route[k];
    }
    cout << '\n';
    return 0;
}