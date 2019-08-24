#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}

int main() {
    int n;
    int sum;
    vector<int> v;
    while(scanf("%1d", &n) == 1) {
        v.push_back(n);
        sum = sum +n;
    }
    if (sum % 3 != 0) {
        cout << "-1";
        return 0;
    }
    sort(v.begin(), v.end(), cmp);
    if (v.back() != 0) {
        cout <<"-1";
        return 0;
    }
    int l = v.size();
    for (int i = 0 ; i < l ; i++)
        cout <<v[i];
}
