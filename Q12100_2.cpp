#include <bits/stdc++.h>
using namespace std;
int n;
int a[21][21];
int a_copy[21][21];
vector <int> direction;
int answer;
void solve(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a_copy[i][j] = a[i][j];
        }
    }
    for(int i=0; i<direction.size(); i++){
        if(direction[i] == 0){ // to right
            for(int i=0; i<n; i++){
                int it = n-1;
                for(int j=n-1; j>=0; j--){
                    if(a_copy[i][j] !=0){
                        if(j == it) it--;
                        else {
                            a_copy[i][it] = a_copy[i][j];
                            a_copy[i][j] = 0;
                            it--;
                        }
                    }
                }
            }
            for(int i=0; i<n; i++){
                for(int j=n-1; j>0; j--){
                    if(a_copy[i][j] == a_copy[i][j-1]){
                        a_copy[i][j] *=2;
                        a_copy[i][j-1] = 0;
                    }
                }
            }
            for(int i=0; i<n; i++){
                int it=n-1;
                for(int j=n-1; j>=0; j--){
                    if(a_copy[i][j]!=0){
                        if(it == j) it--;
                        else {
                            a_copy[i][it] = a_copy[i][j];
                            a_copy[i][j] = 0;
                            it--;
                        }
                    }
                }
            }
        }
        else if(direction [i] ==1){ // down
            for(int j=0; j<n; j++){
                int it = n-1;
                for(int i=n-1; i>=0; i--){
                    if(a_copy[i][j] !=0){
                        if(i == it) it--;
                        else {
                            a_copy[it][j] = a_copy[i][j];
                            a_copy[i][j] = 0;
                            it--;
                        }
                    }
                }
            }
            for(int j=0; j<n; j++){
                for(int i=n-1; i>0; i--){
                    if(a_copy[i][j] == a_copy[i-1][j]){
                        a_copy[i][j] *=2;
                        a_copy[i-1][j] = 0;
                    }
                }
            }
            for(int j=0; j<n; j++){
                int it=n-1;
                for(int i=n-1; i>=0; i--){
                    if(a_copy[i][j]!=0){
                        if(it == i) it--;
                        else {
                            a_copy[it][j] = a_copy[i][j];
                            a_copy[i][j] = 0;
                            it--;
                        }
                    }
                }
            }
        }
        else if(direction[i] == 2){ // to left
            for(int i=0; i<n; i++){
                int it = 0;
                for(int j=0; j<n; j++){
                    if(a_copy[i][j] !=0){
                        if(j == it) it++;
                        else {
                            a_copy[i][it] = a_copy[i][j];
                            a_copy[i][j] = 0;
                            it++;
                        }
                    }
                }
            }
            for(int i=0; i<n; i++){
                for(int j=0; j<n-1; j++){
                    if(a_copy[i][j] == a_copy[i][j+1]){
                        a_copy[i][j] *=2;
                        a_copy[i][j+1] = 0;
                    }
                }
            }
            for(int i=0; i<n; i++){
                int it=0;
                for(int j=0; j<n; j++){
                    if(a_copy[i][j]!=0){
                        if(it == j) it++;
                        else {
                            a_copy[i][it] = a_copy[i][j];
                            a_copy[i][j] = 0;
                            it++;
                        }
                    }
                }
            }
        }
        else if(direction[i] == 3){// up
            for(int j=0; j<n; j++){
                int it = 0;
                for(int i=0; i<n; i++){
                    if(a_copy[i][j] !=0){
                        if(i == it) it++;
                        else {
                            a_copy[it][j] = a_copy[i][j];
                            a_copy[i][j] = 0;
                            it++;
                        }
                    }
                }
            }
            for(int j=0; j<n; j++){
                for(int i=0; i<n-1; i++){
                    if(a_copy[i][j] == a_copy[i+1][j]){
                        a_copy[i][j] *=2;
                        a_copy[i+1][j] = 0;
                    }
                }
            }
            for(int j=0; j<n; j++){
                int it=0;
                for(int i=0; i<n; i++){
                    if(a_copy[i][j]!=0){
                        if(it == i) it++;
                        else {
                            a_copy[it][j] = a_copy[i][j];
                            a_copy[i][j] = 0;
                            it++;
                        }
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
           answer= max(answer, a_copy[i][j]);
        }
    }
}
void go(int cnt){
    if(cnt == 5){
       solve();
       return ;
    }
    for(int i=0; i<4 ; i++){
        direction.push_back(i);
        go(cnt +1);
        direction.pop_back();
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    go(0);
    cout << answer << '\n';
    return 0;
}