    #include <iostream>

    using namespace std;

    int count_five(int x)
    {
        int count = 0;
        while (x % 5 == 0)
        {
            x = x / 5;
            count++;
        }
        return count;
    }

    int main()
    {
        int m, n;
        scanf("%d", &m);
        scanf("%d", &n);
        int a = 0, b = 0;
        n = min(n, m - n);
        for (int i = m - n + 1; i <= m ; i++)
        {
            if ( i % 5 == 0)
                a = a + count_five(i);
        }
        for (int i = 1 ; i <= n ; i++)
        {
            if ( i % 5 == 0)
                b = b + count_five(i);
        }
        if ((a - b < 0 ))
            printf("0");
        else
            printf("%d", a - b);

    }
