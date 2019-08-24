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
#define inf 1000000000

using namespace std;
struct a{
    int start;
    int end;
    int weight;
};

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        bool possible = false;
        int dist[501];
        vector<a> v;
        int n, m, w;
        scanf("%d %d %d", &n, &m, &w);
        v.resize(2*m + w);
        for (int i = 0 ; i < m ; i++) {
            scanf("%d %d %d", &v[i].start, &v[i].end, &v[i].weight);
            v[m +i].start = v[i].end;
            v[m +i].end = v[i].start;
            v[m +i].weight = v[i].weight;
        }
        for (int i = 0 ; i < w ; i++) {
            scanf("%d %d %d", &v[2*m + i].start, &v[2*m + i].end, &v[2*m + i].weight);
            v[2*m + i].weight = (v[2*m + i].weight) * -1;
        }
        for (int i = 1 ; i <= n ; i++)
            dist[i] = inf;
        dist[1] = 0;
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 0 ; j < 2*m + w ; j++) {
                int x = v[j].start;
                int y = v[j].end;
                int z = v[j].weight;
                if (dist[x] != inf && dist[y] > dist[x] + z) {
                    dist[y] = dist[x] + z;
                    if (i == n)
                        possible = true;
                }
            }
        }
        if (possible == false){
            printf("NO\n");
        }
        else {
            bool ans = false;
            for (int i = 0 ; i < 2*m + w; i++) {
                if (v[i].start == 1 && v[i].weight > 0) {
                    ans = true;
                    break;
                }
            }
            if (!ans)
                printf("NO\n");
            else
                printf("YES\n");
        }
        v.clear();


    }








  return 0;
}
