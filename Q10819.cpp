#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >>n;
    vector<int> v(n);
    for (int i = 0 ; i < n ; i++){
        int element;
        cin >>element;
        v[i] = element;
    }
    int maxval = 0;
    sort(v.begin(), v.end());
    do {
        int temp = 0;
        for (int i = 0 ; i < n -1 ; i++) {
            temp = temp + abs(v[i] - v[i+1]);
        }
        if (temp > maxval)
            maxval = temp;
    }
    while (next_permutation(v.begin(), v.end()));
    cout << maxval;
}
