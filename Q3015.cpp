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
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &v[i]);
    }
    deque<long long> s;
    long long ans = 0;
    long long same = 0;
    long long cnt = 0;
    for (int i = 0 ; i < n ; i++) {
        if (s.empty()) {
            same = 0;
            s.push_back(v[i]);

        }
        else if (v[i] < s.back()) {
            same = 0;
            ans++;
            s.push_back(v[i]);

        }
        else if (v[i] > s.back()) {
            cnt = 0;
            same = 0;
            while (!s.empty() && s.back() < v[i]) {
                s.pop_back();
                ans++;
            }
            if (!s.empty()) {
                while(!s.empty() && s.back() == v[i]){
                    cnt++;
                    ans++;
                    s.pop_back();
                }
                if (!s.empty())
                    ans++;
                for (int i = 0 ; i < cnt ; i++)
                    s.push_back(v[i]);
            }
            s.push_back(v[i]);

        }
        else if (v[i] == s.back()) {
            ans++;
            same++;
            ans = ans +(long long) same;
            if (s.front() == v[i])
                ans--;
            s.push_back(v[i]);

        }
    }
    printf("%lld", ans);






  return 0;
}
