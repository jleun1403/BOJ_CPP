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

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int al = a.length();
    int bl = b.length();
    int c = 0;
    stack<char> l;
    stack<char> r;
    stack<char> *temp;
    temp = &l;
    for (int i = 0 ; i < bl ; i++) {
        if (*temp == l) {
            if (a[c] == b[i]) {
                c += 1;
                temp->push(b[i]);
            } else {
                temp->push(b[i]);
                c = 0;
            }
            if (c == al) {
                for (int i = 0 ; i < al ; i++)
                    temp->pop();
                c = al - 1;
                if(*temp == r)
                    *temp = l;
                else
                    *temp = r;
            }
        } else {
            if (a[c] == b[i]) {
                c -= 1;
                temp->push(b[i]);
            } else {
                temp->push(b[i]);
                c = al -1;
            }
            if (c == -1) {
                for (int i = 0 ; i < al ; i++)
                    temp->pop();
                c = 0;
                if(*temp == r)
                    *temp = l;
                else
                    *temp = r;
            }
        }
    }
    int ls = l.size();
    for (int i = 0 ; i < ls; i++) {
       char t = l.top();
       l.pop();
       r.push(t);
       if (t == a[c]) {
            c -= 1;
       }
       else
            c = al - 1;
       if (c == 0) {
            for (int i = 0 ; i < al ; i++)
                r.pop();
            c = al - 1;
       }
    }
    int rs = r.size();
    for (int i = 0 ; i < rs ; i++) {
        printf("%c", r.top());
        r.pop();
    }
















    return 0;
}
