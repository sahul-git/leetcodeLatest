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
    int count = 0;
    pair<int, int> dfs(TreeNode* root){
        if(root == NULL){
            return {0, 0};
        }
        pair<int, int> leftNode = dfs(root->left);
        pair<int, int> rightNode = dfs(root->right);
        int sum = leftNode.first + rightNode.first + root->val;
        int nNode = leftNode.second + rightNode.second + 1;
        if(sum / nNode == root->val) count++;
        
        return {sum,  nNode};
    }
    int averageOfSubtree(TreeNode* root) {
        if(root == NULL) return 0;
        pair<int, int> temp = dfs(root);
        return count;
    }
};