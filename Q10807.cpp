#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n;
    int cases;
    cin >>n;
    vector<int> v(2000);
    for (int i = 0 ; i <n ; i++) {
        cin>>cases;
        v[cases + 100]++;
    }
    scanf("%d", &cases);
    cout << v[cases + 100];

}
