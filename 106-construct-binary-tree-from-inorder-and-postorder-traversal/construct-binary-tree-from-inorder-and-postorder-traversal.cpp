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

    TreeNode* buildPost(vector<int>& postorder, int postStart, int postEnd, 
                        vector<int>& inorder, int inStart, int inEnd, 
                        map<int,int>& inMap) {
        if(postStart > postEnd || inStart > inEnd) return NULL;

        // Root is last element of postorder
        TreeNode* root = new TreeNode(postorder[postEnd]);

        // Find position of root in inorder
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        // Build left and right subtrees
        root->left  = buildPost(postorder, postStart, postStart + numsLeft - 1, inorder, inStart, inRoot - 1, inMap);
        root->right = buildPost(postorder, postStart + numsLeft, postEnd - 1, inorder, inRoot + 1, inEnd, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        map<int,int> inMap;
        for(int i=0; i<n; i++) {
            inMap[inorder[i]] = i;
        }
        return buildPost(postorder, 0, n-1, inorder, 0, n-1, inMap);
    }
};