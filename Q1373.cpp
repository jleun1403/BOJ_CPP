#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>

using namespace std;
string s;
int main() {
    cin >>s;
    int n = s.length();
    int a = n % 3;
    if (a == 1) {
        printf("1");
    }
    else if (a == 2) {
        if (s[0] == '1' && s[1] == '0')
            printf("2");
        else if (s[0] == '1' && s[1] == '1')
            printf("3");
    }
    for (int i = 0 ; i < n/3 ; i++) {
        string t = s.substr(3*i+a, 3);
        if (t == "000")
            printf("0");
        else if (t == "001")
            printf("1");
        else if (t == "010")
            printf("2");
        else if (t == "011")
            printf("3");
        else if (t == "100")
            printf("4");
        else if (t == "101")
            printf("5");
        else if (t == "110")
            printf("6");
        else if (t == "111")
            printf("7");
    }
















  return 0;
}
