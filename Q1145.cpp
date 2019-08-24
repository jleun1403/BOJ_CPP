#include <bits/stdc++.h>
using namespace std;
int a[5];
int d[5][5];
long long answer = 987654321;

int main(){
    int minnum = 987654321;
    for(int i=0; i<5; i++){
        scanf("%d", &a[i]);
        minnum = min(minnum, a[i]);
    }
    for(int i=minnum; ; i++){
        int cnt = 0;
        for(int j=0; j<5; j++){
            if(i % a[j] == 0) cnt +=1;
        }
        if(cnt >=3) {
            answer = i;
            break;
        }
    }
    cout << answer << '\n';
    return 0;
}