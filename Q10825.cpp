#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student{
public:
    string name;
    int korean;
    int english;
    int math;

    Student(string a, int b, int c, int d){
        name = a;
        korean = b;
        english = c;
        math = d;
    }
    bool operator <(Student other){
        if (korean < other.korean)
            return true;
        else if (korean > other.korean)
            return false;
        else {
            if (english > other.english)
                return true;
            else if (english < other.english)
                return false;
            else {
                if (math < other.math)
                    return true;
                else if (math > other.math)
                    return false;
                else {
                    return name > other.name;
                }
            }
        }
    }
};

int main(){
    int n;
    cin >> n;
    vector<Student> v;
    for (int i = 0 ; i < n ; i++) {
        string name;
        int korean, english, math;
        cin >> name >>korean >>english >>math;
        v.push_back(Student(name, korean, english, math));

    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0 ; i < n ; i++)
        cout << v[i].name << '\n';
}
