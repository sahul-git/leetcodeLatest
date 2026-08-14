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
    int maxiDia = 0;
    int diameterMax(TreeNode *root){
        if(root == NULL) return 0;
        int left =  diameterMax(root->left);
        int right =  diameterMax(root->right);
        maxiDia = max(maxiDia, left + right);
        return 1 + max(left, right);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int height = diameterMax(root);
        return maxiDia;
    }
};