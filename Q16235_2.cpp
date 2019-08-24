#include <bits/stdc++.h>
using namespace std;
int n, m , t;
int a[11][11];
int food[11][11]; // 처음 양분 
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
list<pair<int ,pair<int,int>>> Tree; 
int main(){
    cin >> n>> m>> t;
    for(int i=1;i <=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j]; // 추가되는 양분 
            food[i][j] = 5; //초기값 
        }
    }
    for(int i=0; i<m; i++){
        int p, q, num;
        cin >> p>> q >> num;
        Tree.push_back(make_pair(num, make_pair(p,q)));
    }

    while(t--){
        vector <pair <int, pair<int,int>>> die;
        for(auto i= Tree.begin(); i!=Tree.end();){
            int age = i->first;
            int x = i->second.first;
            int y = i->second.second;
            if(age <= food[x][y]){
                food[x][y] -= age;
                i->first +=1;
                ++i;
            }
            else{
                die.push_back(make_pair(age, make_pair(x,y)));
                i =Tree.erase(i);
            }
        }
        for(int i=0; i<die.size(); i++){
            int x = die[i].second.first;
            int y = die[i].second.second;
            int age = die[i].first;
            food[x][y] +=age/2;
        }
          //가을 - 번식 
        for(auto j = Tree.begin(); j!=Tree.end(); j++){
            if(j->first %5==0){
                for(int k=0; k<8; k++){
                    int nx = j->second.first + dx[k];
                    int ny = j->second.second +dy[k];
                    if(nx>=1 && nx <=n && ny >=1 && ny <=n){
                        Tree.push_front(make_pair(1, make_pair(nx,ny)));
                    }
                    else continue;
                }
            }
        }
        //겨울 영양보충 
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                food[i][j] += a[i][j];
            }
        }
    }
        cout << Tree.size()<< '\n';
    
    
    return 0;
}