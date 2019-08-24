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
vector<vector<int>> a;
vector<vector<int>> b;
int n, m, k;
int main() {
    scanf("%d %d", &n, &m);
    a.resize(n, vector<int> (m));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++){
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d %d", &m, &k);
    b.resize(m, vector<int> (k));
    for (int i = 0 ; i < m ; i++){
        for (int j = 0 ; j < k ; j++){
            scanf("%d", &b[i][j]);
        }
    }
    int sum = 0;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < k ; j++){
            sum = 0;
            for (int l = 0 ; l < m ; l++){
                sum += a[i][l] * b[l][j];
            }
            printf("%d ",sum);
        }
        printf("\n");
    }

















  return 0;
}
