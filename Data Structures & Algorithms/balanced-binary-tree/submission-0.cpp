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
    bool isBalanced(TreeNode* root) {
        bool b = true;
        dfs(root, b);
        return b; 
    }
private:
    int dfs(TreeNode* root,bool& b){
        if(root == nullptr) return 0;
        int left = dfs(root->left, b);
        int right = dfs(root->right, b);
        if(right-1 > left || left - 1 > right) b = false;
        return 1 + max(right, left);
    }
};

