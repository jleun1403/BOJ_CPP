#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

int myPow(int x, int p) {
    if (p == 0) return 1;
    if (p == 1) return x;
    int temp = myPow(x, p/2);
    if (p % 2 == 0) return temp * temp;
    else return temp *temp *x;
}
int main(){
    string r1;
    string r2;
    string r3;
    int first;
    int second;
    int third;

    cin >> r1 >> r2 >> r3;
    vector<pair<string, int>> v = {{"black", 0}, {"brown", 1}, {"red", 2}, {"orange", 3}, {"yellow", 4}, {"green", 5}, {"blue", 6}, {"violet", 7},{"grey", 8}, {"white", 9}};
    for (int i = 0 ; i < 10 ; i++) {
        if (r1 == v[i].first)
            first = v[i].second;
        if (r2 == v[i].first)
            second = v[i].second;
        if (r3 == v[i].first)
            third = v[i].second;
    }
    third = myPow(10, third);
    cout << ((first *10 +second) * (long long)third);
}
