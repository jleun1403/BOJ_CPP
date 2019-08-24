#include <iostream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    do
    {
        int upper = 0;
        int lower = 0;
        int space = 0;
        int number = 0;
        for (int i = 0 ; i < s.length() ; i++)
        {
            if (s[i] >= 65 && s[i] <= 90)
                upper++;
            else if (s[i] >= 48 && s[i] <= 57)
                number++;
            else if (s[i] == ' ')
                space++;
            else if (s[i] >= 97 && s[i] <= 122)
                lower++;
        }
        cout << lower << ' ' << upper << ' ' << number << ' ' <<space << '\n';
        getline(cin, s);
    }
    while(s.length() > 0);
}
