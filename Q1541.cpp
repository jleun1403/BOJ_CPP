#include <iostream>
#include <vector>
using namespace std;

int result(string s) {
    int i;
    int l = s.length();
    if (l == 0)
        return 0;
    for (i = 0 ; i < l ; i++) {
        if (s[i] == '+')
            break;
    }
    if (i == l)
        return stoi(s);
    else
        return stoi(s.substr(0, i)) + result(s.substr(i+1));
}

int main(){
    string s;
    cin >> s;
    vector<int> v;
    int l = s.length();
    for (int i = 0 ; i < l ; i++) {
        if (s[i] == '-')
            v.push_back(i);
    }
    int n = v.size();
    if (n == 0) {
        cout << result(s);
        return 0;
    }
    int sum = result(s.substr(0, v[0]));
    for (int i = 0 ; i < n-1 ; i++) {
        sum = sum - result(s.substr(v[i]+1, v[i+1]-v[i]));
    }
    sum = sum - result(s.substr(v[n-1] +1));
    cout << sum;
    return 0;
}
