#include <list>
#include <iostream>
#include <utility>

using namespace std;


int main()
{
    int n;
    int value;
    scanf("%d", &n);
    list<pair<int, int>> balloon;
    for (int i = 1 ; i <= n ; i++)
    {
        scanf("%d", &value);
        balloon.push_back(pair<int, int>(i, value));
    }
    auto it = balloon.begin();

    for (int i = 0 ; i < n-1 ; i++)
    {
        cout << it->first << ' ';
        int step = it->second;
        if (step > 0)
        {
            auto temp = it;
            temp++;
            if (temp == balloon.end())
                temp = balloon.begin();
            balloon.erase(it);
            it = temp;
            for (int i = 1 ; i < step ; i++)
            {
                it++;
                if (it == balloon.end())
                    it = balloon.begin();
            }
        }
        else {
            auto temp = it;
            step = -step;
            if (temp == balloon.begin())
                temp = balloon.end();
            temp--;
            balloon.erase(it);
            it = temp;
            for (int i = 1 ; i <step ; i++) {
                if (it == balloon.begin())
                    it = balloon.end();
                it--;
            }

        }

    }
        printf("%d", balloon.begin()->first);
}
