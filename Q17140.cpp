#include <bits/stdc++.h>
using namespace std;
int a[101][101];
int check[101][101];
vector <pair<int,int>> temp[101];
//vector<pair<int,int>> v[101];
vector<int> v[101];
bool cmp1(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second <= b.second){
        if(a.second == b.second){
            if(a.first <b.first) return true;
            return false;
        }
        else return true;
    }
    else return false;
} 

int main(){
    int r, c, k;
    cin >> r >> c >> k;
    r-=1; c-=1;
    int answer = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &a[i][j]);
            temp[i][j];
        }
        for(int k=0; k<temp[i].size(); k++){
            int y =temp[i][k].second;
           // v[i].push_back(make_pair(k,y));
           v[i].push_back(y);
        }
    }
    cout << "**"<< '\n';
    while(true){
        if(a[r][c] == k) break;
        int rows= sizeof(a) / sizeof(a[0]);
        int cols = sizeof(a[0])/ sizeof(int);
        if(rows >= cols){
            for(int i=0; i<rows; i++){
                sort(v[i].begin(), v[i].end(), cmp1);
                for(int j=0; j<cols; j++){
                    a[i][j] = v[i][j].first;
                    if(j >= v[i].size()){
                        a[i][j++] = 0;
                    }
                }
            }
        }
        else {
            for(int i=0; i<cols; i++){
                sort(v[i].begin(), v[i].end(), cmp1);
                for(int j=0; j<rows; j++){
                    a[i][j] = v[i][j].first;
                    if(j>=v[i].size()){
                        a[i][j++] = 0;
                    }
                }
            }
        }
        answer +=1;
    }
    cout << answer << '\n';
    return 0;
    
}