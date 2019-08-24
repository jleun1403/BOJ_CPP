#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int a[2] = {4,7};
vector<int> answer;
void go(int index, int cnt){
    if(v.size() == cnt){
        string ans = "";
        for(int i=0; i<v.size(); i++){
            ans += to_string(v[i]);
        }
        //cout << ans << '\n';
        answer.push_back(stoi(ans));
        return;
    }
    
    for(int i=0; i<=1; i++){
        v.push_back(a[i]);
        go(index+1, cnt);
        v.pop_back();
    }
   // v.pop_back();
}
int main(){
    int n;
    cin >> n;
    
    int cnt =1;
    while(cnt!=8){
        v.clear();
        go(0, cnt);
        cnt+=1;
    }
    for(int i=0; i<answer.size(); i++){
        if(answer[i]<=n && answer[i+1] >n){
            cout <<answer[i] << '\n';
            break;
        }
    }
    return 0;
}