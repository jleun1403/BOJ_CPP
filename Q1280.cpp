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
#define MAX 200000

using namespace std;
int n;
long long cnt[800050];
long long sum[800050];

long long sum_query(int node, int nodeleft, int noderight, int left, int right) {
    if (noderight < left || right < nodeleft)
        return 0;
    else  if (left <= nodeleft && noderight <= right){
        return sum[node];
    }
    else {
        long long m1 = sum_query(node*2, nodeleft, (nodeleft + noderight)/2, left, right);
        long long m2 = sum_query(node*2+1, (nodeleft+noderight)/2 +1, noderight, left, right);
        return m1 + m2;
    }
}
long long cnt_query(int node, int nodeleft, int noderight, int left, int right) {
    if (noderight < left || right < nodeleft)
        return 0;
    else  if (left <= nodeleft && noderight <= right){
        return cnt[node];
    }
    else {
        long long m1 = cnt_query(node*2, nodeleft, (nodeleft + noderight)/2, left, right);
        long long m2 = cnt_query(node*2+1, (nodeleft+noderight)/2 +1, noderight, left, right);
        return m1 + m2;
    }
}

void update_cnt(int node, int left, int right, int i , int value) {
    if (i < left || i > right)
        return;
    cnt[node] += value;
    if (left != right) {
        update_cnt(node*2, left, (left+right)/2, i, value);
        update_cnt(node*2+1, (left+right)/2+1, right, i, value);
    }
}

void update_sum(int node, int left, int right, int i , int value) {
    if (i < left || i > right)
        return;
    sum[node] += value;
    if (left != right) {
        update_sum(node*2, left, (left+right)/2, i, value);
        update_sum(node*2+1, (left+right)/2+1, right, i, value);
    }
}

int main() {
    memset(cnt, 0, sizeof(cnt));
    memset(sum, 0, sizeof(sum));
    int n;
    scanf("%d" , &n);
    int first;
    scanf("%d", &first);
    update_cnt(1, 0, MAX, first, 1);
    update_sum(1, 0, MAX, first, first);
    long long ans = 1LL;
    for (int i = 2 ;i <= n ; i++) {
        int point;
        scanf("%d", &point);
        long long a1 = sum_query(1, 0, MAX, 0, point-1);
        long long a2 = cnt_query(1, 0, MAX, 0, point-1);
        long long a3 = sum_query(1, 0, MAX, point+1, MAX);
        long long a4 = cnt_query(1, 0, MAX, point+1, MAX);
        update_cnt(1, 0, MAX, point, 1);
        update_sum(1, 0, MAX, point, point);
        ans *= ((point*a2 - a1) + (a3 - a4*point)) % 1000000007;
        ans %= 1000000007;
    }
    printf("%lld", ans);
















  return 0;
}
