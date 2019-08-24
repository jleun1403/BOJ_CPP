#include <iostream>
using namespace std;

int main(){
    string s;
    int sum = 0;
    while(getline(cin, s, ',')) {
        sum = sum + stoi(s);
    }
    cout << sum;
    return 0;
}
