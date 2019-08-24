#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[51][51];
int answer;
vector <int> p;
vector <pair<int,int>> house;
vector <pair<int,int>> chicken;
int dist(pair<int,int> a, pair<int,int> b){
    return abs(a.first-b.first) + abs(a.second-b.second);
}
int main(){
    scanf("%d %d", &n, &m);
    answer = 987654321;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] == 1) house.push_back(make_pair(i,j));
            else if(a[i][j] == 2) chicken.push_back(make_pair(i,j));
        }
    }
    int housenum = house.size();
    int chickennum = chicken.size();
    
    for(int i=0; i<m; i++){
        p.push_back(1);
    }
    for(int i=0; i<chickennum-m; i++){
        p.push_back(0);
    }
    sort(p.begin(),p.end());
    do{
        int road=0;
        for(int i=0; i<housenum; i++){
            int minlen = 987654321;
            for(int j=0; j<chickennum; j++){
                if(p[j] == 1){
                    minlen = min(minlen, dist(house[i], chicken[j]));
                }
            }
            road += minlen;
        }
        answer = min(answer, road);
    }while(next_permutation(p.begin(), p.end()));
    cout << answer << '\n';
    return 0;
}