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
map<string, int> marathon;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        marathon[s]++;
    }
    for (int i = 1 ; i < n ; i++) {
        string s;
        cin >> s;
        marathon[s]--;
    }
    for (auto i = marathon.begin() ; i != marathon.end() ; i++) {
        if ((*i).second == 1) {
            cout << (*i).first;
            return 0;
        }
    }
















  return 0;
}
