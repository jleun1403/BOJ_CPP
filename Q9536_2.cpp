#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    string rem;
    string a= "", b="";
    while(t--){
        cin.ignore();
        getline(cin, a);
        cin.ignore();
        set<string> s;
        vector <string> aa;
        string aaa="";
        vector <string> answer;
        while(true){
            getline(cin, b);
            //cin.ignore();
            cout <<b << '\n';
            if(b == "what does the fox say?"){
                break;
            }
            string temp = "";
            for(int i=b.size()-1; i>=0; i--){
                if(b[i] == ' ') break;
                else temp = b[i] + temp;
            }
            s.insert(temp);
            //cout << '*' << temp << '\n';
        }
        //cout << a.size() << '\n';
        for(int i=0; i<a.size(); i++){
            if(a[i] == ' '){
                if(s.count(aaa) == 0) answer.push_back(aaa);
                //cout << '^' << aaa << '\n';
                aaa = "";
            }
            else aaa+= a[i];
        }
        for(int i=0; i<answer.size(); i++){
            cout << answer[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
/*
1
woof pow
dog goes woof
what does the fox say?
*/