#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>

using namespace std;

int main() {
    vector<char> v;
    vector<int> q;
    int l, c;
    scanf("%d %d", &l, &c);
    for (int i = 0 ; i < c ; i++) {
        char k;
        scanf(" %c", &k);
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    for (int i = 0 ; i < l ; i++)
        q.push_back(0);
    for (int i = 0 ; i < c - l ; i++)
        q.push_back(1);


    do {
        string s = "";
        int mo = 0,ja = 0;
        for (int i = 0 ; i < c; i++) {
            if (q[i] == 0) {
                s = s + v[i];
            if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
                mo++;
            else
                ja++;
            }
        }
        if (mo >= 1 && ja >= 2)
            cout << s <<'\n';


    }  while(next_permutation(q.begin(), q.end()));





  return 0;
}
