#include <vector>
#include <iostream>

using namespace std;
int n;
int tree[26][3];

void preorder(int x){
    if (x == -1)
        return;
    printf("%c", x + 65);
    preorder(tree[x][0]);
    preorder(tree[x][1]);
}
void inorder(int x){
    if (x == -1)
        return;
    inorder(tree[x][0]);
    printf("%c", x + 65);
    inorder(tree[x][1]);
}

void postorder(int x) {
    if (x == -1)
        return;
    postorder(tree[x][0]);
    postorder(tree[x][1]);
    printf("%c", x +65);
}

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        char node;
        char left;
        char right;
        int noden;
        int leftn;
        int rightn;
        scanf(" %c", &node);
        scanf(" %c", &left);
        scanf(" %c", &right);
        noden = node - 65;
        if (left != '.')
            leftn = left - 65;
        else
            leftn = -1;
        if (right == '.')
            rightn = -1;
        else
            rightn = right - 65;
        tree[noden][0] = leftn;
        tree[noden][1] = rightn;
    }
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);




}
