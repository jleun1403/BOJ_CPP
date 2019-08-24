#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>

using namespace std;

class node {
public:
    int val;
    node * left;
    node * right;

    node() {
    }
    };
class BST {

public:
    node *root;
    BST(){
        root = NULL;
    }
    ~BST() {
        root = root -> left = root -> right = NULL;
    }
    void add(int n) {
        inserthelper(n, root);
    }
    void inserthelper(int n, node * &t) {
        if (t == NULL) {
            t = new node;
            t->val = n;
            t->left = NULL;
            t->right = NULL;
            return;
        }
        if (n < t->val)
            inserthelper(n, t->left);
        else if (n > t->val)
            inserthelper(n, t->right);
    }

    string preorder(node * t) {
        if (t == NULL)
            return "";
        string ans = "";
        ans += "V";
        if (t -> left) {
            ans += "L";
            ans += preorder(t->left);
            ans += "l";
        }
        if (t -> right) {
            ans += "R";
            ans += preorder(t->right);
            ans += "r";
        }
        ans += "v";
        return ans;
    }
};


int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    set<string> s;
    for (int i = 0 ; i < n ; i++) {
        BST a;
        for (int j = 0 ; j < k; j++) {
            int temp = 0;
            scanf("%d", &temp);
            a.add(temp);
        }
        cout << a.preorder(a.root);
        s.insert(a.preorder(a.root));

    }
    cout << s.size();







    return 0;
}
