#include <bits/stdc++.h>
using namespace std;
vector<int> v[1001];
bool check[1001];
int n, m, k;
queue <int > q;
void dfs(int x){
    q.push(x);
    check[x] = true;
    cout << x << ' ';
    for(int i=0; i<v[x].size(); i++){
        int y = v[x][i];
        if(check[y] == false){
            dfs(y);
        }
    }

}
int main(){

    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<m; i++){
        int a, b;
        cin >>  a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<=n ; i++){
        sort(v[i].begin(), v[i].end());
    }
    dfs(k);
    cout << '\n';
    memset(check, false, sizeof(check));
     queue <int> q2;
    q2.push(k);
    check[k] = true;
    while(!q2.empty()){
        int x= q2.front();
        q2.pop();
        cout << x << ' ';
        for(int i=0; i<v[x].size(); i++){
            int y = v[x][i];
            if(check[y]==false){
                check[y] =true;
                q2.push(y);
            }
        }
    }
    cout << '\n';


}