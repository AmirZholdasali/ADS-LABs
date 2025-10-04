#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x) : data(x), left(nullptr), right(nullptr){}
};

void bt_insert(Node*& root, int val){
    if(root == nullptr){
        root = new Node(val);
        return;
    }
    if(val < root->data) bt_insert(root->left, val);
    else bt_insert(root->right, val);
}

int subtree_size(Node* root) {
    if(root == nullptr) return 0;
    return 1 + subtree_size(root->left) + subtree_size(root->right);
}

Node* find(Node* root, int x) {
    if(root == nullptr) return nullptr;
    if(root->data == x) return root;
    if(x < root->data) return find(root->left, x);
    else return find(root->right, x);
}

int main(){

    int n, x;
    cin >> n;
    Node* root = nullptr;
    for(int i = 0; i<n; i++){
        cin >> x;
        bt_insert(root, x);
    }

    cin >> x;
    Node* nodeX = find(root, x);

    cout << subtree_size(nodeX);

    return 0;
}