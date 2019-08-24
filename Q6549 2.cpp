#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>

using namespace std;

int main() {
    vector<int> v;
    int n;
    scanf("%d", &n);
    while(n != 0) {
        v.resize(n + 1);
        stack<long long> s;
        long long ans = 0;
        for (int i = 0 ; i < n ; i++)
            scanf("%d" , &v[i]);
        v[n] = -1;
        for (int i = 0 ; i <= n ; i++) {
            int p = 1;
            while(!s.empty() && v[s.top()] > v[i]) {
                long long height = v[s.top()];
                s.pop();
                int width = i;
                if (!s.empty()) width = (i - s.top() - 1);
                long long area = height * width;
                if (area > ans)
                    ans = area;
            }
            s.push(i);
        }
        cout << ans << '\n';



        v.clear();
        scanf("%d", &n);
    }







  return 0;
}
