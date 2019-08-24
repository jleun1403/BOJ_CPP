#include <bits/stdc++.h>
using namespace std;
int n, m , t;
int a[10][10];
int food[10][10]; // 처음 양분 
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
struct Tree{
    int x; 
    int y;
    int age;
    bool live;
};
bool cmp(const Tree &a, const Tree &b){
    return a.x == b.x && a.y == b.y && a.age < b.age;
}
int main(){
    cin >> n>> m>> t;
    for(int i=1;i <=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j]; // 추가되는 양분 
            food[i][j] = 5;
        }
    }
    vector<Tree> v;
    for(int i=0 ; i<m; i++){
        Tree t;
        int p, q, num;
        cin >> p >> q >> num;
        t.x = p;
        t.y = q;
        t.age = num;
        t.live = true;
        v.push_back(t);
    }
    while(t--){
        sort(v.begin(), v.end(), cmp);
        vector<pair<int,pair<int,int>>> temp;
        for(int k=0; k<v.size(); k++){
            int xx= v[k].x;
            int yy= v[k].y;
            if(food[xx][yy]- v[k].age >=0){
                food[xx][yy]-= v[k].age;
                v[k].age+=1;
            }
            else{
                temp.push_back(make_pair(v[k].age, make_pair(v[k].x, v[k].y))); // 죽은 나무 
                v[k].live = false;
            }
        }
        // 가을: 번식
        for(int i=0; i<temp.size(); i++){
            int x = temp[i].second.first;
            int y = temp[i].second.second;
            int age = temp[i].first;
            food[x][y] += (age)/2;
        }
        temp.clear();
        for(int i=0; i<v.size(); i++){
            if(v[i].age % 5 == 0) { // 5의 배수이면 
                int xx= v[i].x;
                int yy = v[i].y;
                for(int j=0; j<8; j++){
                    int nx = xx + dx[j];
                    int ny = yy + dy[j];
                    if(nx>=1 && nx <=n && ny >=1 && ny<=n){
                        Tree t;
                        t.x = nx;
                        t.y = ny;
                        t.age = 1;
                        t.live = true;
                        v.push_back(t);
                    }
                }
            }
        }
        //겨울: 양분 추가
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                food[i][j] += a[i][j];
            }
        }
        //끝 
    }
    int cnt = 0;
    for(int i=0; i<v.size(); i++){
       if(v[i].live == true){
           cnt +=1;
       }
    }
    cout << cnt << '\n';
    return 0;
}