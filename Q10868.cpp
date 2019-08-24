#include <bits/stdc++.h>
using namespace std;

int a[100001];
int tree[300001];

void init(int node, int start, int end) {
	if(start == end) { // leaf node
		tree[node] = a[start];
	} else {
		init(node*2, start, (start+end)/2); // left
		init(node*2+1, (start+end)/2+1, end); // right
		tree[node] = min(tree[node*2], tree[node*2+1]);
	}
}
int query(int node, int start, int end, int i, int j) {
	if(i > end || j < start) return -1; 
	if(i <= start && end <= j) return tree[node]; 
	
	int m1 = query(2*node, start, (start+end)/2, i, j);
	int m2 = query(2*node+1, (start+end)/2+1, end, i, j); 
	
	if(m1 == -1) return m2;
	else if(m2 == -1) return m1;
	else return min(m1, m2); 
} 

int main() {
	int n, m;
    int start, end; 
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
	init(1, 0, n-1);
	for(int i=0; i<m; i++) {
		scanf("%d %d", &start, &end);
		printf("%d\n",query(1, 0, n-1, start-1, end-1)); 
	}
	return 0;
}