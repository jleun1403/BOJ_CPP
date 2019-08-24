#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>
#define inf 987654321

using namespace std;

int main() {
    string s1, s2;
    cin >>s1 >>s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    cout << max(stoi(s1), stoi(s2));
















  return 0;
}
