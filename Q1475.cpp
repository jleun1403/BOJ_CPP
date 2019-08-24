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

using namespace std;

int arr[10];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n == 0){
        printf("1");
        return 0;
    }
    while(n > 0) {
        arr[n%10] += 1;
        n = n / 10;
    }
    int num = 0;
    if ((arr[6] + arr[9]) % 2 == 0)
        num = (arr[6] + arr[9]) / 2;
    else
        num = (arr[6] +arr[9]) / 2 + 1;
    for (int i = 0 ; i < 6 ; i++){
        num = max(num, arr[i]);
    }
    num = max(num, arr[7]);
    num = max(num, arr[8]);
    printf("%d", num);














  return 0;
}
