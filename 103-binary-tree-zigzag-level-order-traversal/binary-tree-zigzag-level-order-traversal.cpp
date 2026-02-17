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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        while(!q.empty()){
            vector<int> level;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                q.pop();
                
                level.push_back(node->val);
            }
            
            if(count %2 == 0) reverse(level.begin(), level.end());

            ans.push_back(level);
            count++;
        }
        return ans;
    }
};