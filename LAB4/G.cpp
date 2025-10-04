#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int x) : data(x), right(nullptr), left(nullptr){}
};

void bt_insert(Node*& root, int val){
    if(root == nullptr){
        root = new Node(val);
        return;
    }
    if(val < root->data) bt_insert(root->left, val);
    else bt_insert(root->right, val);
}

int diameter = 0;

int dfs(Node* root){
    if(!root) return 0;
    int leftH = dfs(root->left);
    int rightH = dfs(root->right);

    diameter = max(diameter, leftH + rightH);

    return 1 + max(leftH, rightH);
}

int diameterOfTree(Node* root) {
    diameter = 0;
    dfs(root);
    return diameter;
}

int main(){
    int n, x;
    cin >> n;
    Node* root = nullptr;

    for(int i = 0; i<n; i++) cin >> x, bt_insert(root, x);

    cout << 1 + diameterOfTree(root) << endl;

    return 0;
}