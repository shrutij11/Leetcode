// 199. Binary Tree Right Side View
// Medium

// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]


vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
       preorder(root,0,ans); 
           return ans;
    }
    public:
    void preorder(TreeNode* root,int level, vector<int> &ans){
        if(root==NULL)return;
        if(ans.size()==level)ans.push_back(root->val);
        preorder(root->right, level+1, ans);
         preorder(root->left, level+1, ans);
    }

//for left view call for left side first
