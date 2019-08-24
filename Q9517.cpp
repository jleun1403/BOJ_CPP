#include <bits/stdc++.h>
using namespace std;
int main(){
    int start, cnt, second =0;
    cin >> start >> cnt;
    int t;
    char ok;
    for(int i=0; i<cnt; i++){
        scanf("%d %c", &t, &ok);
        second +=t;
        if(second >=210) break;
        else {
            if(ok == 'T') {
                start +=1;
                if(start == 9) start = 1;
            }
        }
    }
    cout << start << '\n';
    return 0;
}

