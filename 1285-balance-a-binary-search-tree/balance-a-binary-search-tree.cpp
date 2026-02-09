/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
public:
    // Store inorder traversal
    void inorderTrav(TreeNode* root, vector<int>& inorder) {
        if (!root) return;
        inorderTrav(root->left, inorder);
        inorder.push_back(root->val);
        inorderTrav(root->right, inorder);
    }

    // Build balanced BST from sorted array
    TreeNode* build(vector<int>& inorder, int left, int right) {
        if (left > right) return NULL;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);

        root->left = build(inorder, left, mid - 1);
        root->right = build(inorder, mid + 1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inorderTrav(root, inorder);

        return build(inorder, 0, inorder.size() - 1);
    }
};
