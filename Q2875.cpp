#include <iostream>
using namespace std;

int main(){
    int n, m, k;
    cin >>n >> m >> k;
    int team = 0;
    while ((n + m >= k +3) && n > 1 && m  > 0){
        n = n - 2;
        m = m - 1;
        team++;
    }
    cout <<team;
}
