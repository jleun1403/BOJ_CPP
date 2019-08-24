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
    priority_queue<int> q;
    int n;
    scanf("%d", &n);
    for (int i = 0 ; i <n ; i++) {
        int task;
        scanf("%d", &task);
        if (task == 0) {
            if (q.empty())
                printf("0\n");
            else{
                printf("%d\n", q.top()*-1);
                q.pop();
            }
        }
        else  {
            q.push(task*-1);
        }
    }
















  return 0;
}
