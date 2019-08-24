#include <bits/stdc++.h>
using namespace std;
int arr[101];
int answer;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    for(int i=0; i<3; i++){
        int x, y;
        cin >> x >> y;
        for(int i =x; i<y; i++){
            arr[i] +=1;
        }
    }
    for(int i=1; i<=100; i++){
        if(arr[i] == 1) answer +=a;
        else if(arr[i] == 2) answer += 2*b;
        else if (arr[i] == 3) answer += 3*c;
        else continue;
    }
    cout << answer << '\n';
    return 0;
}