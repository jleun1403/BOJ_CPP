#include <bits/stdc++.h>
using namespace std;
int a[100001];
int min_tree[400001];
int max_tree[400001];
int init(int node, int start, int end){
    if(start == end){
        min_tree[node] = a[start];
        max_tree[node] = a[start];
    }
    else{
        init(node*2, start,(start+end)/2);
        init(node*2 +1, (start+end)/2+1, end);
        min_tree[node] = min(min_tree[node*2], min_tree[node*2 +1]);
        max_tree[node] = max(max_tree[node*2], max_tree[node*2 +1]);
    }
}
int min_query(int node, int start, int end, int i, int j){
    if(end <i || start > j) return -1;
    if(i<= start && j>=end) return min_tree[node];
    int m1 = min_query(node*2, start, (start+end)/2, i, j);
    int m2 = min_query(node*2 +1, (start+end)/2 +1, end,  i, j);
    if(m1 == -1) return m2;
    else if(m2 == -1) return m1;
    else return min(m1, m2);
}
int max_query(int node ,int start, int end, int i, int j){
    if(end <i || start > j) return -1;
    if(i<= start && j>=end) return max_tree[node];
    int m1 = max_query(node*2, start, (start+end)/2, i, j);
    int m2 = max_query(node*2 +1, (start+end)/2 +1, end,  i, j);
    if(m1 == -1) return m2;
    else if(m2 == -1) return m1;
    else return max(m1, m2);   
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    init(1, 0, n-1);
    for(int i=0; i<m; i++){
        int start, end;
        scanf("%d %d", &start, &end);
        int minnum = min_query(1, 0, n-1, start-1, end-1);
        int maxnum = max_query(1, 0, n-1, start-1, end-1);
        printf("%d %d\n", minnum, maxnum);
    }
    return 0;
}