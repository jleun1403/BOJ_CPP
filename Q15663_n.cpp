#include <bits/stdc++.h>

using namespace std;
bool chosen[8];
set<vector<int>> answer;
int n, m;
vector<int> v;

void go(vector<int> choose, int selected) {
    if (selected == m) {
        answer.insert(choose);
        return;
    }
    for (int i = 0; i < n ; i++) {
        if (chosen[i] == false) {
            chosen[i] = true;
            choose.push_back(v[i]);
            go(choose, selected + 1);
            chosen[i] = false;
            choose.pop_back();
        }
    }
    
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i < n ; i++) {
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    vector<int> t;
    go(t, 0);
    //reverse(v.begin(), v.end());
    //go(0);
    /*for (int i = 0 ; i < m ; i++) {
        printf("%d ", answer[0][i]);
    } */
    //printf("\n");
    for (auto i = answer.begin() ; i != answer.end() ; i++) {
        vector<int> t = (*i);
        for (int j = 0 ; j < m ; j++) {
            printf("%d ", t[j]);
        }
        printf("\n");
    }

    return 0;
}