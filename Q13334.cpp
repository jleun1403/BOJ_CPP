#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
vector<pair<int, int>> v;
vector<pair<int, int>> w;
priority_queue<pair<int, int>> q;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a > b)
            swap(a, b);
        v.push_back(make_pair(a, b));
        w.push_back(make_pair(b, a));
    }
    int d;
    scanf("%d", &d);
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    int tail = v[0].first + d;
    int tail_index = 0;
    int ans = 0;
    if (w[0].first <= tail) {
        q.push(make_pair(-w[0].second, -w[0].first));
    }
    for (int i = 0 ; i < n ; i++) {
        tail = v[i].first + d;
        while(true) {
            if (tail_index == n-1)
                break;
            if (w[tail_index + 1].first <= tail) {
                tail_index++;
                q.push(make_pair(-w[tail_index].second, -w[tail_index].first));
            }
            else {
                break;
            }
        }
        while(true) {
            if (!q.empty() && q.top().first*-1 < v[i].first) {
                q.pop();
            }
            else
                break;
        }
        if (q.size() > ans)
            ans = q.size();
    }
    printf("%d", ans);
















  return 0;
}
