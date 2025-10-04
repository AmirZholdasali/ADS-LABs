#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int x) : data(x), right(nullptr), left(nullptr){}
};

Node* bt_insert(Node* root, int val){
    if(root == nullptr)
        return new Node(val);
    if(val < root->data)
        root->left = bt_insert(root->left, val);
    else
        root->right = bt_insert(root->right, val);

    return root;
}

Node* find(Node* root, int val){
    if(root == nullptr) return nullptr;
    if(root->data == val) return root;
    else if(val < root->data) return find(root->left, val);
    else return find(root->right, val);
}

void bt_print(Node* root){
    if(root == nullptr) return;
    cout << root->data << ' ';
    bt_print(root->left);
    bt_print(root->right);
}

int main(){
    int n, k, x;
    Node* root = nullptr;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> x;
        root = bt_insert(root, x);
    }

    cin >> k;
    Node* sub = find(root, k);
    bt_print(sub);
    return 0;
}
