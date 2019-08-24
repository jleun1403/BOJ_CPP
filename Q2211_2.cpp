#include <bits/stdc++.h>
using namespace std;
int parent[1001];
bool check[1001];
vector <pair<int, pair<int,int>>> v;
vector<pair<int,int>> answer;
int Find(int x){
    if( parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}
void Union(int x , int y){
    int xx= Find(x);
    int yy= Find(y);
    parent[yy] = xx;
}

int main(){
    int n, m;
    cin >> n>> m;
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(make_pair(c, make_pair(a,b)));
        v.push_back(make_pair(c, make_pair(b,a)));
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        int cost = v[i].first;
        int from = v[i].second.first;
        int to = v[i].second.second;
        if(Find(from)!= Find(to)){
            Union(from, to);
            answer.push_back(make_pair(from, to));
        }
    }
    cout << answer.size() << '\n';
    for(int i=0; i<answer.size(); i++){
        printf("%d %d\n", answer[i].first, answer[i].second);
    }
    return 0;
}