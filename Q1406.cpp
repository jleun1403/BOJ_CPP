#include <list>
#include <iostream>

using namespace std;

int main(){
    list<char> editor;
    char command;
    char enter;
    int testcase;
    string start;
    cin >> start;

    for (int i = 0 ; i < start.length() ; i++) {
        editor.push_back(start[i]);
    }
    scanf("%d", &testcase);
    auto a = editor.end();
    while(testcase--){
        scanf(" %c", &command);
        if (command == 'L'){
            if (a != editor.begin())
                a--;
        }
        else if (command == 'D') {
            if (a != editor.end())
                a++;
        }
        else if (command == 'B') {
            if (a != editor.begin()){
                auto temp = a;
                temp--;
                editor.erase(temp);
            }
        }
        else if (command == 'P') {
            scanf(" %c", &enter);
            editor.insert(a, enter);
        }
    }
    a = editor.begin();
    for (a = editor.begin() ; a != editor.end(); a++){
        printf("%c", *a);
    }
}
