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
int n;
int a[100001];
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    priority_queue<int > q;
    for (int i = 0 ; i < n; i++)
        cin >> a[i];
    if (n == 1){
        cout << 0;
        return 0;
    }
    for (int i = 0 ; i < n ; i++)
        q.push(-a[i]);

    int sum = 0;
    while(true) {
        int t1 = q.top();
        q.pop();
        int t2 = q.top();
        q.pop();
        sum += (t1 +t2);
        if (q.empty())
            break;
        q.push(t1+t2);
    }
    cout << -sum;
















  return 0;
}
