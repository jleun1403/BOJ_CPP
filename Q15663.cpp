#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10];
int a[10];
bool check[10001];
set<string> s;
set<string> :: iterator it;
int answer;
vector <string> v;
vector<int> num;
bool cmp (const string &s1, const string &s2){
    string a, b;
    for(int i=0; i<s1.size(); i++){
        if(s1[i] !=' ') a+=s1[i];
        else break;
    }
    for(int i=0; i<s2.size(); i++) {
        if(s2[i] != ' ') b+= s2[i];
        else break;
    }
    if(stoi(a) < stoi(b)) return true;
    else return false;
}
void go(int num){
    if(num == m){
        string str;
        for(int i=0; i<m; i++) str += to_string(arr[i]) + " ";
        cout << "**" << str <<'\n'; 
        s.insert(str);
        return;
    }
    for(int i=1; i<=n; i++){
            if(check[i] == false){
            check[i] = true;
            arr[num] = a[i];
            go(num+1);
            arr[num] = 0;
            check[i] = false;
           
        }
    }
}
int main(){
    cin >> n>> m;
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    sort(a+1, a+1+n);
    
    go(0);
    string str;
    
    for(it= s.begin(); it!=s.end(); it++){
        str = *it;
        v.push_back(str);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }
   return 0;
}
/*
4 2
9 7 9 11
*/