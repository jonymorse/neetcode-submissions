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
    vector<vector<int>> order; 
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return order;
    }
private:
    void dfs(TreeNode* root, int depth){
        if(!root) return;
        if(order.size() <= depth){
            order.push_back({});
        }
        order[depth].push_back(root->val);
        dfs(root->left, depth+1);
        dfs(root->right, depth+1);
        return;
    }
};
