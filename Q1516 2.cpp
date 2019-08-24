#include <bits/stdc++.h>
using namespace std;
vector <int> a[501];
int ind[501];
int work[501];
int d[501];
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        scanf("%d", &work[i]);
        while(true){
            int x;
            cin >> x;
            if(x==-1) break;
            a[x].push_back(i);
            ind[i] +=1;
        }
    }
    queue <int> q;
    for(int i=1; i<=n; i++){
        if(ind[i] == 0){
            q.push(i);
            d[i] = work[i];
        }
    }
    for(int k=0; k<n; k++){
        int x = q.front();
        q.pop();
        for(int i=0; i<a[x].size(); i++){
            int y = a[x][i];
            ind[y] -=1;
            if(d[y] < d[x] + work[y])
                d[y] = d[x] +work[y];
            if(ind[y] ==0 )
            q.push(y) ;
        }
    }
    for(int i=1; i<=n; i++){
        printf("%d\n", d[i]);
    }
    return 0;
}