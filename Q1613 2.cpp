#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int > a[401];
int d[401];
int main(){
    cin >> n>> m;
    int x, y;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        a[x].push_back(y);
    }
    int k;
    cin >> k;
    for(int i=0; i<k; k++){
        cin >> x >> y;
        memset(d, 0, sizeof (d));
        queue <int> q;
        q.push(x);
        d[x] = 1;
        while(!q.empty()){
            int nx = q.front();
            q.pop();
            for(int i=0; i<a[nx].size(); i++){
                int ny = a[nx][i];
                if(d[ny] == 0){
                    d[ny] = d[nx] +1;
                    q.push(ny);
                }
            }
        }
        if(d[y] ==0 ){
            memset(d, 0, sizeof(d));
            queue <int > qq;
            qq.push(y);
            d[y] = 1;
            while(!qq.empty()){
                int nx = qq.front();
                qq.pop();
                for(int i=0; i<a[nx].size(); i++){
                    int ny = a[nx][i];
                    if(d[ny] == 0){
                        d[ny] = d[nx]+1;
                        qq.push(ny);
                    }
                }
            }
            if(d[x] == 0){
                printf("0\n");
            }
            else {
                printf("1\n");
            }
        }
        else printf("-1\n");
    }
    return 0;
}