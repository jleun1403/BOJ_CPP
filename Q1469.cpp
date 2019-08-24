#include <bits/stdc++.h>

using namespace std;
int n;
int a[11];
int remain[21];
int made[41];
bool finished;

bool possible(int position, int k) {
    if (remain[k] == 0)
        return false;
    if (remain[k] == 2)
        return true;
    for (int i = 1 ; i < position ; i++) {
        if (made[i] == k) {
             if (position - i - 1 == k)
                return true;
            return false;
        }
    }
    return false;
}

void go(int position) {
    if (position == 2*n + 1) {
        finished = true;
        for (int i = 1 ; i < position ; i++) {
            printf("%d ", made[i]);
        }
        return;
    }
    if (finished)
        return;
    for (int i = 1; i <= n ; i++) {
        int next = a[i];
        if (possible(position, next)) {
            made[position] = next;
            remain[next] -= 1;
            go(position + 1);
            remain[next] += 1;
        }
    }
}


int main() {
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        remain[a[i]] = 2;
    }
    sort(a+1, a+n+1);
    finished = false;
    go(1);
    if (!finished) {
        printf("-1");
    }
    return 0;
}