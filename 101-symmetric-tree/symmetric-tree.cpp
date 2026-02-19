class Solution {
public:

    bool isMirror(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;   
        if(p->val != q->val) return false;

        if(!isMirror(p->left , q->right)){
            return false;
        }
        if(!isMirror(p->right , q->left)){
            return false;
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isMirror(root->left, root->right);
    }
};
