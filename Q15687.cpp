#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
class Rectangle {
private:
    int width;
    int height;
public:

    Rectangle(int width, int height) {
        this->width = width;
        this->height = height;
    }

    int get_width() const {
        return width;
    }
    int get_height() const {
        return height;
    }
    void set_width(int width) {
        this->width = width;
    }
    void set_height(int height) {
        this->height = height;
    }
    int area() const {
        return width * height;
    }
    int perimeter() const{
        return 2*(width + height);
    }
    bool is_square() const {
        return width == height;
    }
};
