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
#include <map>

using namespace std;
int a[3][3];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int main() {
    string start;
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0)
                a[i][j] = 9;
            start += to_string(a[i][j]);
        }
    }
    if (start == "123456789"){
        printf("0");
        return 0;
    }
    map<int ,int> d;
    int t = stoi(start);
    d[t] = 0;
    queue<int> q;
    q.push(t);
    while(!q.empty()) {
        int cur = q.front();
        string now = to_string(cur);
        q.pop();
        int z = now.find('9');
        int x = z / 3;
        int y = z % 3;
        for (int i = 0 ; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
                string next = now;
                swap(next[z], next[3*nx + ny]);
                int nextnum = stoi(next);
                if (d[nextnum] == 0) {
                    d[nextnum] = d[cur] +1;
                    q.push(nextnum);
                }
            }
        }
    }
    if (d[123456789] == 0)
        printf("-1");
    else
        printf("%d", d[123456789]);



















  return 0;
}
