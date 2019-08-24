#include <bits/stdc++.h>
using namespace std;
int a[51][51];
vector <pair<int,int>> house;
vector <pair<int,int>> chicken;
int house_num, chicken_num;
int n, m;
int dist(pair<int,int> a, pair<int,int> b){
    return abs(a.first-b.first) + abs(a.second-b.second);
}
int main(){
int ans = 987654321;
    cin >> n>> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            if(a[i][j] ==1) house.push_back(make_pair(i,j));
            else if (a[i][j] ==2) chicken.push_back(make_pair(i,j));
        }
    }
    house_num = house.size();
    chicken_num = chicken.size();
    vector <int> p(chicken_num);
    for(int i=0; i<chicken_num; i++){
        if(i<m){
            p[i] = 0;
        }
        else p[i] = 1;
    }
    do{
        int sum = 0;
        for(int i=0; i<house_num; i++){
            int minlen = 987654321;
            for(int j=0; j<chicken_num; j++){
                if(p[j] == 0) minlen =min(minlen, dist(house[i],chicken[j]));
            }
            sum += minlen;
        }
        ans = min(ans, sum);

    }while(next_permutation(p.begin(), p.end()));
    cout << ans << '\n';
    return 0;
}