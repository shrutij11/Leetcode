class Solution {
public:
    vector<int> getLonelyNodes(TreeNode* root) {

        vector<int> res;
        dfs(root, res);
        return res;
    }

private:
    void dfs(TreeNode* node, vector<int>& res){

        if(!node) return;

        if(node->left && !node->right)
            res.push_back(node->left->val);

        if(!node->left && node->right)
            res.push_back(node->right->val);

        dfs(node->left, res);
        dfs(node->right, res);
    }
};
