#include <bits/stdc++.h>
using namespace std;
int a[100001];
bool check[100001];
int cnt[100001];
queue<int> q;
int answer;
void dfs(){
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        answer +=1;
        cnt[a[temp]]-=1;
        if(cnt[a[temp]] == 0){
            q.push(a[temp]);
        }
    }
}
int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        answer = 0;
        memset(a, 0, sizeof(a));
        memset(check,false,sizeof(check));
        memset(cnt , 0, sizeof(cnt));
        for(int i=1; i<=n; i++){
           scanf("%d", &a[i]);
           cnt[a[i]] +=1;
        }
        for(int i=1; i<=n; i++){
            if(cnt[i] == 0){
                q.push(i);
            }
        }
        dfs();
        cout << answer << '\n';
    }
    return 0;
}