#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int myPow(int n , int p) {
    if (p == 0)
        return 1;
    if (p == 1)
        return n;
    if (p % 2 == 1)
        return myPow(n, p/2) * myPow(n, p/2) *n;
    else
        return myPow(n, p/2) * myPow(n, p/2);
}

int H(int n, int p) {
    int sum = 0;
    string s = to_string(n);
    int length = s.length();
    for (int i = 0 ; i < length ; i++) {
        sum = sum + myPow((s[i] - 48), p);
    }
    return sum;

}

int main(){
    int A;
    int p;
    cin >> A >> p;
    vector<int> v(100000, -1);
    v[0] = A;
    int i = 1;
    while (true) {
        int j;
        v[i] = H(v[i-1], p);
        for (j = 0 ;  j < i- 1 ; j++){
            if (v[i] == v[j])
                break;
        }
        if (v[i] == v[j])
            break;
        i++;
    }
    int k = 0;
    for (k = 0 ; k < 100000 ; k++) {
        if (v[k] == -1)
            break;
    }
    int j = 0 ;
    for (j = 0 ; j < k ; j++){
        if (v[j] == v[k-1])
            break;
    }
    cout << j;



}


