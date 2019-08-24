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
    int n;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int t = 0 ; t < n ; t++) {
        string s1, s2;
        cin >> s1 >> s2;
        printf("Distances: ");
        for (int i = 0 ; i < s1.length() ; i++) {
            printf("%d ", (s2[i] - s1[i]) >= 0 ? (s2[i]-s1[i]) : (s2[i] - s1[i] +26) );
        }
        printf("\n");
    }
















  return 0;
}
