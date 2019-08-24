#include <bits/stdc++.h>
using namespace std;
int a[17][17];
int a_copy[17][17];
vector <int> v;
int n, m, d;
int ans;
int t;
int answer;

queue <pair<int,int>> q;
void solve(){
    t = 0;
    ans =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            a_copy[i][j] = a[i][j];
        }
    }
    while(true){
        for(int k=0; k<v.size(); k++){
            int x = n;
            int y = v[k]; // 열 
            bool ok = false;
            int mindist = 987654321;
            for(int i=n-1; i>=0; i--){
                for(int j=0; j<m; j++){
                    if(a_copy[i][j] ==1  && abs(x-i) + abs(y-j)<=d ){
                        mindist = min (mindist, abs(x-i) + abs(y-j));
                    }
                } 
            }
            for(int j=0; j<m; j++){
                for(int i= n-1; i>=0; i-- ){
                    if(abs(x-i) + abs(y-j) == mindist && a_copy[i][j] == 1){
                        q.push(make_pair(i,j)); //enemy 
                        ok = true;
                        break;
                    }
                }
                if(ok == true) break;
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            if(a_copy[x][y] == 1){
                a_copy[x][y] = 0;
                ans+=1;
            }
            q.pop();
        }
        //이동 
        t+=1;
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<m; j++){
                a_copy[i+1][j] = a_copy[i][j];
            }
        }
        for(int j=0; j<m; j++) a_copy[0][j] = 0;

        if(t == n) {
            break;
        }
    }
    answer = max(answer, ans);
}
int main(){
    answer = 0;
    cin >> n>> m>> d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>> a[i][j];
        }
    }
    
    for(int p=0; p<m-2; p++){
        for(int q=p+1; q<m-1; q++){
            for(int k = q+1; k<m; k++){
                v.push_back(p);
                v.push_back(q);
                v.push_back(k);
                solve();
                v.clear();
            }
        }
    }
    cout << answer << '\n';
    return 0;
}