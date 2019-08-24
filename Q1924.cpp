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
int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string s[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main() {
    int m, d;
    scanf("%d %d", &m, &d);
    int sum = 0;
    for (int i = 1; i < m ; i++) {
        sum += a[i];
    }
    sum += (d - 1);
    cout << s[sum % 7];


















  return 0;
}
