#include <iostream>
#include <vector>
#define MAX 2100000000

using namespace std;

int main(){

    vector<int> v(5001);
    v[1] = MAX;
    v[2] = MAX;
    v[3] = 1;
    v[4] = MAX;
    v[5] = 1;
    for (int i = 6 ; i <= 5000 ; i++){
        v[i] = min(v[i-3], v[i-5]) +1;
    }
    int n;
    cin >>n;
    if (v[n] >= MAX)
        cout <<"-1";
    else
        cout << v[n];
}
