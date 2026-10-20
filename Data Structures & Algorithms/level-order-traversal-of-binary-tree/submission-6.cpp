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
        vector<vector<int>> order; 
        dfs(root, 0, order);
        return order;
    }
private:
    void dfs(TreeNode* root, int depth, vector<vector<int>>& order){
        if(!root) return;
        else if(!root && !order.empty()) order[depth].push_back(-1);
        if(order.size() <= depth){
            order.push_back({});
        }
        order[depth].push_back(root->val);
        dfs(root->left, depth+1, order);
        dfs(root->right, depth+1, order);
        return;
    }
};
