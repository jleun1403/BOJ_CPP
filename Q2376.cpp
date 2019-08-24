#include <iostream>
#include <algorithm>

using namespace std;
int n;
int v[1000];
int parent[1001];
int ancestor[1001];

int main() {
	scanf("%d", &n);
	int parent_number = n + 1;
	for (int i = 1; i < n; i++) {
		scanf("%d", &v[i]);
		parent[i] = i;
		ancestor[i] = i;
	}

	parent[n] = n;
	ancestor[n] = n;

	for (int i = 1; i < n; i++) {
		if (v[i] == 2) {
			int leftmost;
			int rightmost;
			int k = ancestor[i];
			int l = ancestor[i + 1];
			parent[k] = parent[l] = parent_number;
			for (int j = 1; j <= n; j++) {
				if (ancestor[j] == k || ancestor[j] == l) {
					ancestor[j] = parent_number;
					leftmost = j;
					break;
				}
			}
			for (int j = n; j >= 1; j--) {
				if (ancestor[j] == k || ancestor[j] == l) {
					ancestor[j] = parent_number;
					rightmost = j;
					break;
				}
			}
			for (int j = leftmost; j <= rightmost; j++) {
				if (ancestor[j] == k || ancestor[j] == l) {
					ancestor[j] = parent_number;
				}
			}
			printf("%d %d\n", leftmost, rightmost);
			if (leftmost != 1)
				v[leftmost - 1] -= 1;
			if (rightmost != n)
				v[rightmost] -= 1;
			parent_number++;
			v[i] = 0;
			i = 1;
		}
	}
	printf("%d\n", parent_number);
	return 0;
}