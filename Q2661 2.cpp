#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

int a[81];
int n;
bool finished;

bool possible(int position, int k) {
    a[position] = k;
    for (int i = 1 ; i <= position ; i++) {
        int start1 = position - i*2 + 1;
        int start2 = position - i + 1;
        if (start1 <= 0)
            break;
        for (int j = 0 ; j < i ; j++) {
            if (a[start1 + j] != a[start2 + j]) {
                break;
            }
            if (j == i-1 && a[start1 + j] == a[start2 + j])
                return false;
        }
    }
    return true;
}

void go(int i) {

    if (i == n + 1) {
        for (int j = 1 ; j <= n ; j++) {
            printf("%d", a[j]);
        }
        finished = true;
        return;
    }

    if (finished)
        return;
    for (int k = 1 ; k <= 3 ; k++) {

        if (possible(i, k)) {

            if (!finished) go(i+1);
        }
    }
}

int main() {
    scanf("%d", &n);
    finished = false;
    go(1);
















  return 0;
}
