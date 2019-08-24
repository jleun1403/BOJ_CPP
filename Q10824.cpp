#include <iostream>
using namespace std;

int main(){
    int a, b, c, d;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    string ab = to_string(a) + to_string(b);
    string cd = to_string(c) + to_string(d);
    cout << stoll(ab) + stoll(cd);
}
