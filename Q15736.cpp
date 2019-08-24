#include <iostream>
using namespace std;

int main(){
    int n, answer=0;
    cin >> n;
    for(int i=1; i*i<=n; i++){
        if(i*i <=n) answer+=1;
    }
    cout << answer << '\n';
    return 0;
}