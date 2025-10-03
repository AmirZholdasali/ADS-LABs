#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x) : data(x), left(nullptr), right(nullptr){}
};

Node* bt_insert(Node* root, int val){
    if(root == nullptr){
        return new Node(val);
    }
    if(val < root->data){
        root->left = bt_insert(root->left, val);
    }
    else{
        root->right = bt_insert(root->right, val);
    }

    return root;
}

bool check(Node*& root, string s){
    Node* cur = root;
    for(int i = 0; i<s.size(); i++){
        if(cur == nullptr) return false;
        else if(s[i] == 'L') cur = cur->left;
        else if(s[i] == 'R') cur = cur->right;
    }

    if(cur != nullptr) return true;
    else return false;
}

int main(){

    int n, m, x;
    string s;
    cin >> n >> m;
    Node* root = nullptr;
    for(int i = 0; i<n; i++) cin >> x, bt_insert(root, x);

    for(int i = 0; i<m; i++){
        cin >> s;
        if(check(root, s)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}