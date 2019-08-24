#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[51][51];
int a_copy[51][51];
int d[51][51];
int answer = 987654321;
vector<pair<int,int>> v;
vector <int> op;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int main(){
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
          scanf("%d", &a[i][j]);
          if(a[i][j] == 2){
              a[i][j] = 1;
              v.push_back(make_pair(i,j));
          }
          else if (a[i][j] == 1) a[i][j] = -1;
      }
  }
  for(int i=0; i< m; i++){
      op.push_back(1);
  }
  for(int i=0; i<v.size()-m; i++){
      op.push_back(0);
  }
  sort(op.begin(), op.end());
  bool ok = false;
  do{
      ok = false;
      int ans = 0;
      memset(d, 0, sizeof(d));
      for(int i=0; i<n; i++){
          for(int j=0; j<n; j++){
              a_copy[i][j] = a[i][j];
          }
      }
      queue <pair<int,int>> q;
      for(int i=0; i<op.size(); i++){
          if(op[i] == 1){
              int x = v[i].first;
              int y = v[i].second;
              //a_copy[x][y] = 3;
              q.push(make_pair(x,y));
              d[x][y] = 1;
          }
      }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >=0 && nx <n && ny >=0 && ny < n && d[nx][ny] == 0 && a_copy[nx][ny]!= -1){
                d[nx][ny] = d[x][y] +1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    for(int i=0 ; i<n; i++){
        for(int j=0; j<n; j++){
            if(d[i][j] == 0 && a_copy[i][j] !=-1) ok = true;
        }
    }
    
    if(ok == false){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(d[i][j] >=2) ok = false;
                ans = max(ans, d[i][j]-1);
            }
        }
    }
    else ans = -1;
    if(ans != -1) answer= min(answer,ans);
    
    }while (next_permutation(op.begin(),op.end()));
    if(answer == 987654321) cout << -1 << '\n';
    else cout << answer << '\n';

    return 0;
}