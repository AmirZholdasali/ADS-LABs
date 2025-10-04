#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *right, *left;
    Node(int x) : data(x), right(nullptr), left(nullptr){}
};


void bt_insert(Node*& root, int val){
    if(!root){
        root = new Node(val);
        return;
    }
    if(val < root->data) bt_insert(root->left, val);
    else bt_insert(root->right, val);
}


int bt_triangle_count(Node* root, int &cnt){
    if(!root) return 0;
    if(root->right && root->left) cnt++;
    bt_triangle_count(root->left, cnt);
    bt_triangle_count(root->right, cnt);



    return cnt;
}


int main(){
    int n, x;
    cin >> n;
    Node* root = nullptr;
    for(int i = 0; i<n; i++){
        cin >> x;
        bt_insert(root, x);
    }
    int cnt = 0;
    cout << bt_triangle_count(root, cnt) << endl;
    return 0;
}