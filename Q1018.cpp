#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[52][52];
int answer =987654321;
char cnt1[9][9], cnt2[9][9];
int num1, num2;
int go(int x, int y){
    //cnt1 -> white start, cnt2-> black start
    num1 = 0, num2 =0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(a[x+i][y+j] != cnt1[i][j]){
                num1+=1;
            }
            if(a[x+i][y+j] != cnt2[i][j]){
                num2+=1;
            }
        }
    }
    //if(x ==0 && y ==5) cout << "** " << min(num1, num2) << '\n';;
    return min(num1, num2);
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            a[i][j] = s[j];
        }
    }
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if((i+j)%2==0){
                cnt1[i][j] ='B';
                cnt2[i][j] ='W';
            }
            else {
                cnt1[i][j] = 'W';
                cnt2[i][j] = 'B';
            }

        }
    }
    for(int i=0 ; i<=n-8; i++){
        for(int j=0; j<=m-8; j++){
            answer = min(answer, go(i,j));
        }
    }
    printf("%d\n", answer);
    return 0;
}