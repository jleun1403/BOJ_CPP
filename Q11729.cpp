#include <iostream>

using namespace std;
int mypow(int a, int b) {
    if (b == 1)
        return a;
    else return a*mypow(a, b-1);
}

void hmove(int start, int temp, int goal, int n) {
    if (n == 1){
        cout << start << ' '<< goal<<'\n';
    }
    else {
        hmove(start, goal, temp, n-1);
        cout << start <<' ' << goal<<'\n';
        hmove(temp, start, goal, n-1);
    }
}
int main(){
    int n;
    cin >> n;
    cout << mypow(2, n) - 1<<'\n';
    hmove(1, 2, 3, n);
}
