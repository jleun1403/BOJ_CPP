#include <iostream>
#include <algorithm>
#include <vector>
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
    stack<int> s;
    string st;
    cin >> st;
    int k;
    int ans = 0;
    for (int i = 0 ; i < st.length() ; i++) {
        if (s.empty()) {
            k = i;
        }
        if (st[i] == '(' || st[i] == '[') {
            s.push(st[i]);
        }
        else {
            if (s.empty()) {
                printf("0");
                return 0;
            }
            if (st[i] == ']' && s.top() == '(') {
                printf("0");
                return 0;
            }
            else if (st[i] == ')' && s.top() == '[') {
                printf("0");
                return 0;
            }
            else {
                int temp = 0;
                if (st[i] == ')') {
                    if (s.top() == '(') {
                        s.pop();
                        s.push(2);
                    }
                    else {
                        while(s.top() != '(') {
                            temp += s.top();
                            s.pop();
                            if (s.top() == '[') {
                                printf("0");
                                return 0;
                            }
                        }
                        s.pop();
                        s.push(temp * 2);
                    }
                }
                if (st[i] == ']') {
                    if (s.top() == '[') {
                        s.pop();
                        s.push(3);
                    }
                    else {
                        while(s.top() != '[') {
                            temp += s.top();
                            s.pop();
                            if (s.top() == '(') {
                            printf("0");
                            return 0;
                        }
                        }
                        s.pop();
                        s.push(temp * 3);
                    }
                }
            }
        }
    }
    while (!s.empty()) {
        if (s.top() == '(' || s.top() == '[' || s.top() == ')' || s.top() == ']') {
            printf("0");
            return 0;
        }
        else
            ans += s.top();
        s.pop();
    }
    printf("%d", ans);
















  return 0;
}
