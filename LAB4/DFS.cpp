//inorder (left->root->right)
void dfs_inorder(Node* root) {
    if (!root) return;            // если узел пустой — выходим

    dfs_inorder(root->left);      // обходим левое поддерево
    cout << root->data << " ";    // обрабатываем текущий узел
    dfs_inorder(root->right);     // обходим правое поддерево
}


//preorder (root->left->right)
void dfs_preorder(Node* root) {
    if (!root) return;

    cout << root->data << " ";    // обрабатываем узел
    dfs_preorder(root->left);     // левое поддерево
    dfs_preorder(root->right);    // правое поддерево
}


//postorder (left->right->root)
void dfs_postorder(Node* root) {
    if (!root) return;

    dfs_postorder(root->left);    // левое поддерево
    dfs_postorder(root->right);   // правое поддерево
    cout << root->data << " ";    // обработка узла в конце
}
