#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Вставка в BST
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Обратный inorder: правый → корень → левый
void transform(Node* root, int& sum) {
    if (!root) return;

    transform(root->right, sum);     // идём в большее поддерево
    sum += root->data;               // добавляем значение текущего узла
    root->data = sum;                // заменяем ключ на накопленную сумму
    transform(root->left, sum);      // идём в меньшее поддерево
}

// Обычный inorder для вывода (лево → корень → право)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int sum = 0;
    transform(root, sum); // заменяем ключи

    inorder(root); // вывод в порядке возрастания
}
