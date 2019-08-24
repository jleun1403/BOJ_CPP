#include <bits/stdc++.h>
using namespace std;

int main(){
    int cnt, n ,m;
    cin >> cnt >> m >> n;
    double sq = 0;
    sq = sqrt((pow(m,2) + pow(n,2)));
    int a; 
    for(int i=0; i<cnt; i++){
        scanf("%d", &a);
        if(a <= sq) printf("DA\n");
        else printf("NE\n");
    }
    return 0;
}