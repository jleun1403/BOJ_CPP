#include <bits/stdc++.h>
using namespace std;
bool check[201][201];
vector <int> v;
bool used[201];
int answer;
int n, m;
bool is_ok(){
    bool ok = false;
    for(int i=0; i<v.size()-1; i++){
        for(int j=i+1; j<v.size(); j++){
            if(check[v[i]][v[j]] == true ) return false;
        }
    }
    if(ok == false) return true;
}
void go(){
    /*if(v.size() == 3) {
        
        if(is_ok() == true){
        cout << v[0] << ' ' << v[1] <<  ' ' << v[2] << '\n';    
            answer +=1;
            return;
        }
        else return;
    }
    for(int i=1; i<=n; i++){
        if(used[i] == false){
            v.push_back(i);
            used[i] = true;
            go();
            used[i] = false;
            v.pop_back();
        }
    }
    */
   for(int i=1; i<=n-2; i++){
       for(int j=i+1; j<=n-1; j++){
           for(int k=j+1; k<=n; k++){
               v.push_back(i);
               v.push_back(j);
               v.push_back(k);
               if(is_ok() == true) {
                   answer+=1;
               }
               v.clear();
           }
       }
   }
   return ;
}
int main(){
    cin >> n>> m;
    int a, b;
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        check[a][b] = true;
        check[b][a] = true;
    }
    go();
    cout << answer<< '\n';
    return 0;
}