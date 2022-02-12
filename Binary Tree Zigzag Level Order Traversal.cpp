// 103. Binary Tree Zigzag Level Order Traversal
// Medium

// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]

 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)return result;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=true;
     
        while(q.size()){
               int size=q.size();
            vector<int>row(size);
            for(int i=0; i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                int index= (flag)?i:(size-1-i);
                row[index]=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);    
            }
             flag=!flag;
        result.push_back(row);
        }
        return result;
       
    }
