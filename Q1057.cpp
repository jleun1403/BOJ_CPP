#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int xnum;
int ynum;
int main(){
    scanf("%d %d %d", &n, &x, &y);
    if(x>y) swap(x,y);
    vector<int> v;
    int cnt=0;
    while(x!=y){
        if(x%2==0) x= x/2;
        else x = x/2+1;
        if(y%2 ==0) y = y/2;
        else y = y/2+1;
        cnt+=1;
    }
    cout<< cnt<< '\n';
    return 0;
}