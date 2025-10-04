void dfs_inorder(Node* root) {
    if (!root) return;            // если узел пустой — выходим

    dfs_inorder(root->left);      // обходим левое поддерево
    cout << root->data << " ";    // обрабатываем текущий узел
    dfs_inorder(root->right);     // обходим правое поддерево
}
