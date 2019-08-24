#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    vector<string> look;
    vector<string> watch;
    vector<string> result;

    for (int i = 0 ; i < n ; i++) {
        string l;
        cin >> l;
        look.push_back(l);
    }
    sort(look.begin(), look.end());
    for (int i = 0 ; i < m ; i++) {
        string w;
        cin >> w;
        watch.push_back(w);
    }
    for (int i = 0 ; i < m ; i++) {
        if (binary_search(look.begin(), look.end(), watch[i])) {
            result.push_back(watch[i]);
        }
    }
    cout << result.size() << '\n';
    sort(result.begin(), result.end());
    for (int i = 0 ; i < result.size() ; i++)
        cout << result[i] << '\n';
}
