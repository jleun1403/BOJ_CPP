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
#define inf 987654321

using namespace std;
int n;
vector<string> v;



int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ;i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    if ( n == 1) {
        printf("%d %c", v[0].length(), v[0][v[0].length() / 2]);
    }
    for (int i = 0 ; i< n ;i++){
        for (int j = i; j< n ; j++) {
            string temp = v[j];
            reverse(temp.begin(), temp.end());
            if (v[i] == temp) {
                printf("%d %c", v[i].length(), v[i][v[i].length() / 2]);
            }
        }
    }

















  return 0;
}
