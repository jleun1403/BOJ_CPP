#include <bits/stdc++.h>
using namespace std;
vector <string> answer;
string a, b, rem;
int main(){
    int k;
    cin >> k;
    getline(cin , rem);
    while(k--){
        getline(cin, a);
        set<string> s;
        vector <string> aa;
        string aaa="";
        answer.clear();
        while(true){
            getline(cin, b);
            if(b == "what does the fox say?"){
                break;
            }
            string temp = "";
            for(int i=b.size()-1; i>=0; i--){
                if(b[i] == ' ') break;
                else temp = b[i] + temp;
            }
            s.insert(temp);
        }
        for(int i=0; i<a.size(); i++){
            if(a[i] == ' '){
                if(s.count(aaa) == 0) answer.push_back(aaa);
                aaa = "";
            }
            else aaa+= a[i];
        }
        if(s.count(aaa) ==0) answer.push_back(aaa);
        for(int i=0; i<answer.size(); i++){
            cout << answer[i] << ' ';
        }
        cout << '\n';
        cin.clear();
    }
    return 0;
}
/*
1
woof pow
dog goes woof
what does the fox say?
*/
/*
1
woof pow
dog goes woof
what does the fox say?
*/