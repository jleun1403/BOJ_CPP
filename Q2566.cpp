#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    pair<int ,int> max_pair;
    int maxans = 0;

    for (int i = 1; i <= 9 ; i++){
        for (int j = 1 ; j <= 9 ; j++) {
            int a;
            scanf("%d", &a);
            if (a > maxans) {
                maxans = a;
                max_pair.first = i;
                max_pair.second = j;
            }
        }
    }
    printf("%d\n%d %d", maxans, max_pair.first, max_pair.second);
}
