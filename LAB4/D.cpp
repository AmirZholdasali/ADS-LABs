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

int bt_levels(Node* root){
    if(root == nullptr) return 0;
    return 1 + max(bt_levels(root->left), bt_levels(root->right));
}

vector<int> levelSums(Node* root) {
    vector<int> sums;
    if (root == nullptr) return sums;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();   // количество узлов на этом уровне
        int sum = 0;
        for (int i = 0; i < sz; i++) {
            Node* cur = q.front(); q.pop();
            sum += cur->data;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        sums.push_back(sum);
    }
    return sums;
}

int main(){
    int n, x;
    Node* root = nullptr;
    cin >> n;

    for(int i = 0; i<n; i++) cin >> x, bt_insert(root, x);

    cout << bt_levels(root) << endl;

    vector<int> sums = levelSums(root);
    for (int i = 0; i < sums.size(); i++) {
        cout << sums[i] << ' ';
    }

    return 0;
}