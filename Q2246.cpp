#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int n;
vector<pair<int , int >> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    v.resize(n);
    for (int i = 0 ; i <n ; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    int ans = 1;
    pair<int, int> compare = v[0];
    for (int i = 1 ;i < n ; i++) {
        if (v[i].first == compare.first)
            continue;
        if (v[i].second < compare.second) {
            ans++;
            compare = v[i];
        }
    }
    printf("%d\n", ans);















  return 0;
}
