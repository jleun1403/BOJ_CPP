#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Point{
public:
    int x;
    int y;
    Point(int a, int b){
        x = a;
        y = b;
    }
    bool operator <(const Point& other){
        if (this->y < other.y)
            return true;
        else if (this->y == other.y)
            return this->x < other.x;
        return false;
    }
};

int main(){
    int n;
    int x, y;
    scanf("%d", &n);
    vector<Point> v;
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &x);
        scanf("%d", &y);
        v.push_back(Point(x, y));
    }
    sort(v.begin(), v.end());
    for (int i = 0 ; i < n ; i++)
        printf("%d %d\n", v[i].x, v[i].y);
}
