#include <iostream>

using namespace std;

int main()
{
    int bd[50];
    int n, length = 0;
    scanf("%d", &n);
    if (n == 0){
        printf("0");
        return 0;
    }
    while (n != 1)
    {
        if (n%(-2) > 0)
            bd[length] = (n % (-2));
        else
            bd[length] = (n % (-2)) *(-1);
        if ((n < 0) && (bd[length] == 1))
            n = n *(-1) / 2 + 1;
        else
            n = n / (-2);
        length++;
    }
    bd[length] = 1;

    for (int i = length; i >= 0 ; i--)
    {
        printf("%d", bd[i]);
    }
}
