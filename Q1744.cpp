#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    deque<int> v;
    int n;
    cin >> n;
    if (n == 0){
        cout << "0";
        return 0;
    }
    int cnt1 = 0, cntm = 0, cnt0 = 0, cntp = 0;
    for (int i = 0 ; i < n ; i++) {
        int k;
        cin >>k;
        v.push_back(k);
        if (k == 1)
            cnt1++;
        if (k < 0)
            cntm++;
        if (k == 0)
            cnt0++;
        if (k > 1)
            cntp++;
    }
    sort(v.begin(), v.end());
    int sum = 0;
    if (cntm % 2 == 0) {
        while (!v.empty() && v.front() < 0){
            int x = v.front();
            v.pop_front();
            int y = v.front();
            v.pop_front();
            sum = sum + (x*y);
        }
        while (!v.empty() && v.front() == 0){
            v.pop_front();
        }
        while (!v.empty() && v.front() == 1){
            v.pop_front();
            sum++;
        }
        while(v.size() > 1){
            int w = v.back();
            v.pop_back();
            int z = v.back();
            v.pop_back();
            sum = sum + (w *z);
        }
        if (v.size() > 0)
            sum = sum + v.back();

    }
    else {
        int p = 0;
        while (p < cntm / 2){
            int x = v.front();
            v.pop_front();
            int y = v.front();
            v.pop_front();
            sum = sum + (x*y);
            p++;
        }
        if (cnt0 > 0){
            v.pop_front();
        }
        else {
            sum = sum + v.front();
            v.pop_front();
        }
        while (!v.empty() && v.front() == 0){
            v.pop_front();
        }
        while (!v.empty() && v.front() == 1){
            v.pop_front();
            sum++;
        }
        while(v.size() > 1){
            int w = v.back();
            v.pop_back();
            int z = v.back();
            v.pop_back();
            sum = sum + (w *z);
        }
        if (v.size() > 0)
            sum = sum + v.back();

    }
    cout << sum;
}
