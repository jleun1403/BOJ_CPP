#include <bits/stdc++.h>
using namespace std;
vector <pair<int,int>> v[1001];
int dist[1001];
int parent[1001];
int main(){
    int n, m;
    cin>> n>> m;
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    for(int i=1; i<=n; i++){
       priority_queue <pair<int,int>> q;
       for(int j=1; j<=n; j++){
           parent[j] = j;
           dist[j] = 987654321;
       }
       dist[i] = 0;
       q.push(make_pair(0,i));
       while(!q.empty()){
           int cost= -q.top().first;
           int now = q.top().second;
           q.pop();
           for(int i=0; i<v[now].size(); i++){
               int next = v[now][i].first;
               int ncost = v[now][i].second;
               if(dist[next] > dist[now] + ncost){
                   dist[next] = dist[now] + ncost;
                   q.push(make_pair(-dist[next], next));
                   parent[next] = now;
               }
           }
       }
       for(int j=1; j<=n; j++){
           if( j == i) printf("- ");
           else {
               int temp = j;
               while(parent[temp]!=i){
                   temp = parent[temp];
               }
               printf("%d ", temp);
           }
       }
       printf("\n");
    }
    return 0;
}