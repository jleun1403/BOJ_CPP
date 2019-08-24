#include <bits/stdc++.h>
using namespace std;
vector <int> a[10001];
vector <int> b[10001];
int ind[10001];
int out[10001];
int work[10001][10001];
int d[10001];
bool check[10001];
int main(){
    int n, m;
    cin >> n;
    cin >> m;
    for(int i=0; i<m; i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        a[x].push_back(y);
        b[y].push_back(x);
        work[x][y] = z;
        ind[y] +=1;
        out[x] +=1;
    }
    int start, end;
    cin >> start >> end;
    queue <int> q;
    q.push(start);
    d[start] = 0;
    
    for(int k=0; k<n; k++){
        int x = q.front();
        q.pop();
        for(int i =0; i<a[x].size(); i++){
            int y = a[x][i];
            ind[y] -=1;
            if(d[y] < d[x] + work[x][y])
            d[y] = d[x] + work[x][y];
            if(ind[y] == 0) q.push(y);
        }
    }
    cout << d[end] << '\n';
    queue <int> ans;
    check[end] = true;
    bool ok = false;
    ans.push(end);
    vector< int> answer;
    answer.push_back(end);
    for(int k=0; k<n; k++){
        int x= ans.front();
        ans.pop();
        for(int i=0; i<b[x].size(); i++){
            int y = b[x][i];
            out[y] -=1;
            //printf("%d ", y);
            if(y == start && check[x] == true) {
                    ans.push(start);
                    answer.push_back(start);
                    cout << answer.size()<<'\n';
                    return 0;
                }
            if(d[x] - d[y] == work[y][x] && check[x] == true){
                check[y] = true;
            }
            else check[y] = false;
            if(out[y] == 0 && check[y] == true){
                ans.push(y);
                answer.push_back(y);
               // cout << "** ";
            }
        }
    }
    return 0;
}