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
    int maxdia = 0;
    int diameter(TreeNode* root){
        if(root == NULL) return 0;

        int left = diameter(root->left);
        int right = diameter(root->right);
        maxdia = max(left + right, maxdia);
        return 1 + max(left, right) ;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int height =  diameter(root);
        return maxdia;
    }
};