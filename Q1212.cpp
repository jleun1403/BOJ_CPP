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

int main() {
    string s;
    cin >> s;
    if (s == "0") {
        printf("0");
        return 0;
    }
    switch(s[0]) {
    case '1':
        printf("1");
        break;
    case '2':
        printf("10");
        break;
    case '3':
        printf("11");
        break;
    case '4':
        printf("100");
        break;
    case '5':
        printf("101");
        break;
    case '6':
        printf("110");
        break;
    case '7':
        printf("111");
        break;
    }
    for (int i = 1 ; i < s.length() ; i++) {
        switch(s[i]) {
    case '0' :
        printf("000");
    case '1':
        printf("001");
        break;
    case '2':
        printf("010");
        break;
    case '3':
        printf("011");
        break;
    case '4':
        printf("100");
        break;
    case '5':
        printf("101");
        break;
    case '6':
        printf("110");
        break;
    case '7':
        printf("111");
        break;
    }
    }
















  return 0;
}
