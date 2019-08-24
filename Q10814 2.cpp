#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Score{
public:
    int age;
    string name;

    Score(int a, string b){
        age = a;
        name = b;
    }
    bool operator <(const Score& other){
        return age < other.age;
    }
};

int main() {
    int n;
    int score;
    string name;
    scanf("%d", &n);
    vector<Score> v;
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &score);
        cin >>name;
        v.push_back(Score(score, name));
    }
    sort(v.begin(), v.end());
    for (int i = 0 ; i < n ; i++) {
        cout << v[i].age << " " << v[i].name << endl;
    }
}
