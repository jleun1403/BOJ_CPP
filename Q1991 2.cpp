#include <bits/stdc++.h>
using namespace std;
int n;
struct Node{
    int left;
    int right;
};
struct Node arr[100];
void preorder(char root){
    if(root == '.'){
        return ;
    }
    else{
        cout << root;
        preorder(arr[root].left);
        preorder(arr[root].right);
    }
}
void inorder(char root){
    if(root == '.'){
        return ;
    }
    else{
        inorder(arr[root].left);
        cout<<root;
        inorder(arr[root].right);
    }
}
void postorder(char root){
    if(root == '.'){
        return ;
       
    } 
    else{
        postorder(arr[root].left);
        postorder(arr[root].right);
        cout << root;
    }
}
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        char c1, c2, c3;
        cin >>c1 >> c2 >> c3;
        arr[c1].left = c2;
        arr[c1].right = c3;
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';
    return 0;
}