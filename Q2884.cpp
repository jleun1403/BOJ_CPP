#include <bits/stdc++.h>
using namespace std;

int main(){
    int hour, minute;
    cin >> hour>> minute;
    if(minute >=45){
        minute-=45;
    }
    else{
       minute+=15;
       hour-=1;
       if(hour <0) hour =23;
        
    }
    printf("%d %d\n", hour, minute);
    return 0;
}