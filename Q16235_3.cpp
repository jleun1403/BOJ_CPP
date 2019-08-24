#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[11][11];
int food[11][11];
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
list <pair<int, pair<int,int>>> tree;
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
            food[i][j] = 5;
        }
    }
    for(int i=0; i<m; i++){
        int p, q, w;
        scanf("%d %d %d", &p , &q, &w);
        tree.push_back(make_pair(w, make_pair(p ,q)));
    }
    while(k--){
        vector<pair<int, pair<int,int>>> die;
        for(auto i = tree.begin(); i!=tree.end();){
            int age = i->first;
            int x = i->second.first;
            int y = i->second.second;
            if(age <=food[x][y]) {
                food[x][y] -= age;
                i->first +=1;
                i++;
            }
            else{
                die.push_back(make_pair(age, make_pair(x,y)));
                i = tree.erase(i);
            }
        }
        for(int i=0; i<die.size(); i++){
            int age = die[i].first;
            int x = die[i].second.first;
            int y = die[i].second.second;
            food[x][y] += age/2;
        }
        for(auto i = tree.begin(); i!=tree.end(); i++){
            if(i->first %5 ==0){
                for(int j=0; j<8; j++){
                    int nx = i->second.first + dx[j];
                    int ny = i->second.second + dy[j];
                    if(nx >=1 && nx <=n && ny >=1 && ny <=n){
                        tree.push_front(make_pair(1, make_pair(nx,ny)));
                    }
                }
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                food[i][j] +=a[i][j];
            }
        }
    }
    cout << tree.size() << '\n';
    return 0;
}
