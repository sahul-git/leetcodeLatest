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
    int depth(TreeNode *node){
        if(node == NULL) return 0;
        int left = depth(node->left);
        if(left == INT_MAX ) return INT_MAX;
        int right = depth(node-> right);
        if( right == INT_MAX) return INT_MAX;
        if(abs(left - right) > 1) return INT_MAX;
        return max(left, right) + 1;

    }

    bool isBalanced(TreeNode* root) {
        int d = depth(root);
        if(d == INT_MAX) return false;
        return true;
    }
};