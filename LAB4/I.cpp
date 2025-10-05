#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    int mult;
    Node *right, *left;
    Node(int x) : data(x), mult(1), right(nullptr), left(nullptr) {}
};

void insert(Node*& root, int val) {
    if (!root) {
        root = new Node(val);
        return;
    }
    if (val == root->data) {
        root->mult++;
        return;
    }
    if (val < root->data) insert(root->left, val);
    else insert(root->right, val);
}

Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* succ = root->right;
            while (succ->left)
                succ = succ->left;

            root->data = succ->data;
            root->mult = succ->mult;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}

Node* cntNode(Node* root, int x) {
    if (!root) return nullptr;
    if (root->data == x) return root;
    if (x < root->data) return cntNode(root->left, x);
    else return cntNode(root->right, x);
}

int main() {
    int n, val;
    string s;
    Node* root = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> val;
        if (s == "insert") insert(root, val);
        else if (s == "delete") {
            Node* node = cntNode(root, val);
            if (node) {
                node->mult--;
                if (node->mult <= 0)
                    root = deleteNode(root, val);
            }
        }
        else if (s == "cnt") {
            Node* node = cntNode(root, val);
            cout << (node ? node->mult : 0) << endl;
        }
    }
    return 0;
}
