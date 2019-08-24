#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class myString
{
public:
    string s;
    myString(string s1){
        s = s1;
    }
    bool operator< (myString s1)
    {
        if (s.length() < s1.s.length())
            return true;
        else if (s.length() > s1.s.length())
            return false;
        else
        {
            return s < s1.s;
        }
    }
};



int main()
{
    int n;
    cin >> n;
    vector<myString> v;
    for (int i = 0 ; i < n ; i++)
    {
        string q;
        cin >> q;
        v.push_back(myString(q));
    }
    sort(v.begin(), v.end());

    cout << v[0].s << '\n';
    for (int i = 1 ; i < n ; i++)
        if (v[i].s != v[i-1].s)
            cout << v[i].s <<'\n';
}
