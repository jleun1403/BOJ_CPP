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

using namespace std;
int n, r, c;
int solve(int row, int col, int n) {
    if (n == 1) {
        if (row == 0 && col == 0)
            return 0;
        else if (row == 0 && col == 1)
            return 1;
        else if (row ==1 && col == 0)
            return 2;
        else
            return 3;
    }
    else {
        int length = (1<<n);
        if (row < length/2 && col < length/2) {
            return solve(row, col, n-1);
        }
        else if (row < length/2 && col >= length/2) {
            return length * length /4 * 1 + solve(row, col-length/2, n-1);
        }
        else if (row >= length/2 && col < length/2) {
            return length *length /4 *2 + solve(row-length/2, col, n-1);
        }
        else{
            return length*length/4 *3 + solve(row-length/2, col-length/2, n-1);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &r, &c);
    printf("%d ", solve(r, c, n));

















  return 0;
}
