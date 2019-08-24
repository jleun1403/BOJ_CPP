#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y, n, m;
    cin >> x >> y >> n>> m;
    int answer = 987654321;
    answer= min(answer, x);
    answer= min(answer, y);
    answer= min(answer, n-x);
    answer= min(answer, m-y);
    cout << answer << '\n';
    return 0;
}