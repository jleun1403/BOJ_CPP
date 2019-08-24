#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int n, m;
int dp[(1<<20)][21];
bool check[(1<<20)][21];
int a[21];

int main() {
    int n;
    scanf("%d %d", &n);
    int p, q;
    scanf("%d %d", &p, &q);
    int initial = (1<<(p-1)) | (1<<(q-1));
    int m;
    scanf("%d", &m);
    for (int i = 1 ; i <= m ; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x-1;
    }

    for (int i = 1 ; i <= m ; i++) {

        for (int j = 0 ; j < (1<<n) ; j++) {
            int val = j;
            val = val & (val - 1);
            if (val == 0) continue;
            val = val & (val - 1);
            if (val != 0) continue;

        }
    }
















  return 0;
}
