#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *right, *left;
    Node(int x) : data(x), left(nullptr), right(nullptr){}
};


Node* find(Node* root, int val){
    if(root == nullptr) return nullptr;
    if(root->data == val) return root;
    Node* l = find(root->left, val);
    if(l) return l;
    return find(root->right, val);
}


void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


void bfs(Node* root, vector<int> &lvls) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();      // количество узлов на текущем уровне
        lvls.push_back(size);     // сохраняем ширину уровня

        for (int i = 0; i < size; i++) {
            Node* cur = q.front();
            q.pop();

            // cout << cur->data << " "; // обработка узла

            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
}



void xyz_insert(Node*& root, int x, int y, int z){
    if(!root){
        root = new Node(x);
    }
    else{
        Node* rootX = find(root, x);
        if(z == 0){
            rootX->left = new Node(y);
        }
        else{
            rootX->right = new Node(y);
        }
    }
}


int main() {
    int n, x, y, z;
    cin >> n;

    Node* root = nullptr;

    // первая строка ввода
    cin >> x >> y >> z;
    root = new Node(x);  // создаём корень
    xyz_insert(root, x, y, z);

    // оставшиеся n-2 строк
    for (int i = 1; i < n-1; i++) {
        cin >> x >> y >> z;
        xyz_insert(root, x, y, z);
    }

    // проверка обхода
    // inorder(root);
    // cout << "\n";

    // BFS
    vector<int> lvls;
    bfs(root, lvls);

    auto max_it = max_element(lvls.begin(), lvls.end());
    cout << *max_it << "\n";

    return 0;
}
