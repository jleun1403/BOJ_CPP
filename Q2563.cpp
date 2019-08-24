#include <bits/stdc++.h>
using namespace std;
bool check[101][101];
int main(){
    int n, x, y;
    cin >> n;
    while(n--){
        cin >> x >> y;
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                if(check[x+i][y+j] == false) check[x+i][y+j] = true;
            }
        }
    }
    int answer= 0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(check[i][j] == true) answer +=1;
        }
    }
    cout << answer << '\n';
    return 0;
}