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

vector<int> v;
bool a[1001];
void go(){
    memset(a, true, sizeof(a));
    a[0] = false;
    a[1] = false;
    a[2] = true;
    for (int i = 2 ; i <= 1000 ; i++) {
        if (a[i] == false)
            continue;
        v.push_back(i);
        for (int j = i*i ; j <= 1000 ; j += i) {
            a[j] = false;
        }
    }
}

int main() {
    go();
    int testcase;
    scanf("%d", &testcase);
    while(testcase--) {
        int n;
        scanf("%d", &n);
        bool flag = false;
        for (int i = 0 ; i < v.size() ; i++) {
            for (int j = i ; j < v.size() ; j++) {
                for (int k = j ; k < v.size() ; k++) {
                    if (v[i] + v[j] + v[k] == n) {
                        printf("%d %d %d\n", v[i], v[j], v[k]);
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }
        if (!flag)
            printf("%d\n", 0);
    }
















  return 0;
}
