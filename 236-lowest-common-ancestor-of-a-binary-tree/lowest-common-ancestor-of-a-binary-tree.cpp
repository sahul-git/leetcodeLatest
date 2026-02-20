/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if( root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCA(root->left, p, q);
        TreeNode* right = lowestCA(root->right, p, q);
        if(!left ) return right;
        if(!right ) return left;
        
        return root;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lowestCA(root, p, q);

    }
};