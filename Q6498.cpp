#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if( n>=90 && n <=100) printf("A\n");
    else if (n>=80) printf("B\n");
    else if(n>=70) printf("C\n");
    else  if(n >=60) printf("D\n");
    else printf("F\n");
    return 0;
}