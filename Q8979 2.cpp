#include <bits/stdc++.h>
using namespace std;
struct Country{
    int num;
    int gold;
    int silver;
    int bronze;
};

bool cmp(const Country &c1, const Country &c2){

    return  (c1.gold>c2.gold) || (c1.gold==c2.gold && c1.silver >c2.silver) || (c1.gold==c2.gold && c1.silver == c2.silver && c1.bronze >c2.bronze) ;
}
int main(){
    int n, k;
    cin >> n>> k;
    vector <Country> v;
    for(int i=0; i<n; i++){
        Country c;
        
        int n, x, y, z;
        cin >> n >> x >>y >> z;
        c.num = n;
        c.gold = x;
        c.silver = y;
        c.bronze = z;
        v.push_back(c);
    }
    sort(v.begin(), v.end(), cmp);
    
    int grade = 0;
    for(int i=0; i<n; i++){
        if(v[i].num == k){
            grade = i;
            break;
        }
    }
    //cout << "***" << grade << '\n';
    int n_grade = 0;
    if(grade == 0) {
    cout << "1\n";
            return 0;
    }
    for(int i=grade-1; i>=0; i--){
       
        if((v[i].gold == v[grade].gold) && (v[i].silver == v[grade].silver) && (v[i].bronze == v[grade].bronze)){
            continue;
        }
        else {
            n_grade =i;
            break;
        }
    }   
    //cout <<" **" << n_grade << '\n';
   
    cout<< n_grade +2 << '\n';
    return 0;
}