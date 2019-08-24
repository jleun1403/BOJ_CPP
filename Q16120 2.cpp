#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int state = 0; // 1,2,3,4 P PP PPA PPAP
    string input;
    cin >> input;

    if (input == "P") { cout << "PPAP" << '\n';  return 0; }
    else if ((input[input.size() - 1] != 'P') || (input[input.size() - 2] != 'A') || (input[0] != 'P')) { cout << "NP" << '\n'; return 0; }
    else {
        while (input != "P") {
            int i = 0;
            bool flag = false;
            for (i = 0; i < input.size(); i++) {
                if (input[i] == 'P') {
                    if ((state <= 1) || (state == 3)) state++;
                    else if (state == 2) state = 2;

                }
                else { // A
                    if (state == 2) state = 3;
                    else state = 0;
                }
                //cout << state << " ";
                if (state == 4) {
                    input.replace(input.begin() + i - 3, input.begin() + i+1, "P");
                    state = 0;
                    //cout << endl << input << endl;
                    flag = true;
                    break;
                }
            }
            //for문 end
            // 끝까지 갔는데 PPAP 못 찾음
            if ((i == input.size())&&(!flag)) {
                cout << "NP" << '\n';
                  return 0;
            }
        }
        cout << "PPAP" << '\n';    return 0;

    }

    return 0;
}
