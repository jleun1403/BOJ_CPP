#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        return 0;
    }
    while ( n != 1)
    {
        int i = 2;
        while ((n % i != 0)&&(i <= sqrt(n)))
            i++;
        if (n % i != 0) {
            printf("%d\n", n);
            n = 1;
        }
        else {
            printf("%d\n", i);
        n = n / i;
        }
    }
    return 0;
}
