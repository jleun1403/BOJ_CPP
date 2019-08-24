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
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
    int n;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        int a;
        scanf("%d", &a);
        if (i % 2 == 0) {
            q1.push(a);
        }
        else
            q2.push(a);
        if (!q2.empty() && q1.top() > q2.top()) {
            int x = q1.top();
            int y = q2.top();
            q1.pop();
            q2.pop();
            q2.push(x);
            q1.push(y);
        }
        printf("%d\n", q1.top());
    }
















  return 0;
}
