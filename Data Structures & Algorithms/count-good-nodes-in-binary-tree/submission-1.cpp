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
    int count = 0; 
    
    int goodNodes(TreeNode* root) {
        int min = root->val; 
        dfs(root, min);
        return count;
    }
private:
    void dfs(TreeNode* root, int min){
        if(!root) return;
        if(root->val >= min){
            min = root->val;
            count++;
            dfs(root->left, min);
            dfs(root->right, min);
        }
        else{
            dfs(root->left, min);
            dfs(root->right,min);
        }
    }
};
