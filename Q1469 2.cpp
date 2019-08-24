#include <bits/stdc++.h>
using namespace std;
int a [41];
int remain[100];
int n;
int answer[41];
bool found;

bool isok(int index, int what) {
    if (remain[what] == 0)
        return false;
    if (remain[what] == 2)
        return true;
    for (int i = 1 ; i < index ; i++) {
        if (answer[i] == what) {
            if (index - i -1 == what)
                return true;
            return false;
        }
    }
}
void go(int index){
    if(index == 2*n+1){
        found = true;
        for(int i=1; i< index; i++){
            printf("%d ", answer[i]);
        }
        return;
    }
    if(found) 
        return;
    for(int i=1; i<=n; i++){
        if(isok(index, a[i])){
            answer[index] = a[i];
            remain[a[i]] -=1;
            go(index+1);
            remain[a[i]] +=1;  
        }
    }
}
int main(){
    scanf("%d", &n);
    int x;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        remain[a[i]] = 2;
    }
    sort(a+1, a+n+1);
    //found = false;
    go(1);
    if(!found) 
        printf("-1\n");
    return 0;
}