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
    dfs(root,0);
    return order;
    }
private:
    void dfs(TreeNode* root, int level){
        if(!root) return;
        if(order.size() == level){
            order.push_back({});
        }
        order[level].insert(order[level].end(), root->val);
        level++;
        dfs(root->left, level);
        dfs(root->right, level);
        return;
    }
};
