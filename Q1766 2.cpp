#include <bits/stdc++.h>
using namespace std;
vector <int> a[32001];
int ind[32001];
int main(){
    int n, m;
    cin >> n>> m;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        ind[y] +=1;
    }
    priority_queue <int> q;
    for(int i=1; i<=n; i++){
        if(ind[i] == 0){
            q.push(-i);
        }
    }
    for(int k=0; k<n; k++){
        int x = -q.top();
        q.pop();
        printf("%d ", x);
        for(int i=0; i<a[x].size(); i++){
            int y = a[x][i];
            ind[y] -=1;
            if(ind[y] == 0){
                q.push(-y);
            }
        }
    }
    cout << '\n';
    return 0;
}