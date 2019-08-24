#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int score[100];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int ans = 0;
    int answerid = inf;
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &score[i]);
    }
    for (int i = 0 ; i < m ; i++) {
        int id;
        scanf("%d", &id);
        int s = 0;
        for (int j = 0 ; j < n ; j++) {
            char c;
            scanf(" %c", &c);
            if (c == 'O') {
                s += score[j];
            }
        }
        if (s > ans) {
            ans = s;
            answerid = id;
        }
        else if (s == ans) {
            answerid = min(answerid, id);
        }
    }
    printf("%d %d", answerid, ans);
















  return 0;
}
