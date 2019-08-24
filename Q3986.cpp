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
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int cnt = 0;
    while(n--) {
        cin >> s;
        stack <char> st;
        bool flag = true;
        for (int i = 0 ; i < s.length() ; i++) {
            if (st.empty()) {
                st.push(s[i]);
            }
            else {
                if (s[i] == st.top()) {
                    st.pop();
                }
                else {
                    st.push(s[i]);
                }
            }
        }
        if (!st.empty())
            flag= false;
        while(!st.empty()) {
            st.pop();
        }
        if (flag)
            cnt++;
    }
    cout << cnt;















  return 0;
}
