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
int r, g;
vector<int> divisors;

int GCD (int x, int y) {
    if ( y ==0 )return x;
    else return GCD(y, x % y);
}

int divisor(long long x){
    int cnt = 0;
    for (long long i = 1 ; i*i<= x; i++) {
        if (x % i == 0) {
            cnt++;
            divisors.push_back(i);
            if (i*i != x) {
                cnt++;
                divisors.push_back(x/i);
            }
        }
    }
    return cnt;
}

int main() {
    scanf("%d %d",&r, &g);
    int x = GCD(r, g);
    for (int i = 0 ; i < divisor(x) ; i++) {
        printf("%d %d %d\n", divisors[i], r / divisors[i], g / divisors[i]);
    }

















  return 0;
}
