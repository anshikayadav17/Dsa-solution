class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushLeft(TreeNode* root) {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (node->right != nullptr) {
            pushLeft(node->right);
        }

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};
