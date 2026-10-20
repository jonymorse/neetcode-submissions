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

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q; 
        if(!root) return res;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> level = {};

            for(int i = 0; i < size; i++){
                TreeNode* n = q.front();
                level.push_back(n->val);
                if(n->left != nullptr) q.push(n->left);
                if(n->right != nullptr) q.push(n->right);
                q.pop();
            }
            res.push_back(level);
        }
        return res;
    }

};
