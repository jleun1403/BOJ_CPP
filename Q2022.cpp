#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
double x, y, c;

using namespace std;
bool possible(double x, double y, double t) {
    double p = sqrt(pow(x, 2) - pow(t, 2));
    double q = sqrt(pow(y, 2) - pow(t, 2));
    return (p*q / (p+q) > c);
}

int main() {
    while(scanf("%lf %lf %lf", &x, &y, &c) == 3) {
        double left = 0.0000000;
        double right = min(x, y) * 2;
        double mid;
        for (int i = 0 ; i <100 ; i++) {
            mid = (left +right)/ 2;
            if (possible(x, y, mid))
                left = mid;
            else
                right = mid;
        }
        printf("%.3lf\n", );
    }









  return 0;
}
