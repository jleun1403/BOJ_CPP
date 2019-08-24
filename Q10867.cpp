#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int testcase;
    cin >> testcase;
    vector<int> v;
    for (int i = 0 ;i < testcase ; i++) {
        int element;
        scanf("%d", &element);
        v.push_back(element);
    }
    sort(v.begin(), v.end());
    cout << v[0] << ' ';
    for (int i = 1 ; i < testcase ; i++) {
        if (v[i] != v[i-1])
            cout << v[i] << ' ';
    }

}
