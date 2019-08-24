#include <bits/stdc++.h>
using namespace std;
vector <int> bricks;
int last[10001];
int main(){
    int n, a;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        bricks.push_back(a);
    }
    int answer = 0;
    for (int i = 0 ; i <= 10000 ; i++) {
        last[i] = -1;
    }
    for (int i = 0 ; i < n ; i++) {
        int height = bricks[i];
        for (int j = 1 ; j <= height ; j++) {
            if (last[j] == -1)
                break;
            answer += (i - last[j] - 1);
            cout << i-last[j] -1 << '\n';;
        }
        for (int j = 1 ; j <= height ; j++) {
            last[j] = i;
        }
    }	
	cout << answer << '\n';
    return 0;

}