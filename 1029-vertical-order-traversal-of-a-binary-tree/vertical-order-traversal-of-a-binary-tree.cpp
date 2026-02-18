class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<pair<int, pair<int,int>>> nodes; 
        

        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});  

        while(!q.empty()) {

            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int row = front.second.first;
            int col = front.second.second;

            nodes.push_back({node->val, {row, col}});

            if(node->left)
                q.push({node->left, {row+1, col-1}});

            if(node->right)
                q.push({node->right, {row+1, col+1}});
        }

       
        sort(nodes.begin(), nodes.end(), [](auto &a, auto &b) {

            if(a.second.second == b.second.second) {
                if(a.second.first == b.second.first)
                    return a.first < b.first;
                return a.second.first < b.second.first;
            }
            return a.second.second < b.second.second;
        });

        vector<vector<int>> result;
        int prevCol = INT_MIN;

        for(auto &node : nodes) {

            int value = node.first;
            int col = node.second.second;

            if(col != prevCol) {
                result.push_back({});
                prevCol = col;
            }

            result.back().push_back(value);
        }

        return result;
    }
};
