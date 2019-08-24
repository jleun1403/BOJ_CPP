#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int a[10001];
int temp[10001];
int n;

bool same() {
    for (int i = 1 ; i<= n ; i++) {
        if (a[i] != i)
            return false;
    }
    return true;
}
pair<int , int> one() {
    for (int i = 1 ; i<= n ; i++) {
        if (a[i] != i) {
            int first = a[i];
            if (a[first] == i)
                return make_pair(i, first);
            else return make_pair(0, 0);
        }
    }
}

void overlap() {
    int start, end;
    for (int i = 1 ; i <= n ; i++) {
        if (a[i] != i) {
            start = i;
            break;
        }
    }
    for (int i = n ; i >= 1 ; i --) {
        if (a[i] != i) {
            end = i;
            break;
        }
    }
    int start2,end2;
    for (int i = 1 ; i <= n ; i++) {
        if (a[i] == start) {
            start2 = i;
            break;
        }
    }
    reverse(temp+start, temp+start2+1);

    for (int i = 1 ; i <= n ; i++) {
        if (temp[i] == end) {
            end2 = i;
            break;
        }
    }
    reverse(temp+ end2, temp+end+1);
    int i;
    for (i = 1 ; i <= n ; i++) {
        if (temp[i] != i)
            break;
    }
    if(i == n+1) {
        printf("%d %d\n%d %d", start, start2, end2, end);
    }
    else {
        for (int i = 1; i <= n ; i++) {
            if (a[i] == end) {
                end2 = i;
                break;
            }
        }
        reverse(a+end2, a+end+1);
        for (int i = 1 ; i <= n; i++) {
            if(a[i] == start) {
                start2 = i;
            }
        }
        printf("%d %d\n%d %d", end2, end, start, start2);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i++) {
        scanf("%d", &a[i]);
        temp[i] = a[i];
    }
    if (same()) {
        printf("1 1\n1 1");
        return 0;
    }
    pair<int, int> p = one();
    if (p.first == 0 && p.second == 0) {
        overlap();
        return 0;
    }
    reverse(a+p.first , a + p.second + 1);
    if (same()) {
        printf("%d %d\n1 1", p.first, p.second);
        return 0;
    }
    pair<int, int> q = one();
    printf("%d %d\n%d %d", p.first, p.second, q.first, q.second);


















  return 0;
}
