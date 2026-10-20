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

    TreeNode* invertTree(TreeNode* root) {
        TreeNode* temp = root;
        if(!temp) return temp;
        TreeNode* l = temp->left;
        TreeNode* r = temp->right;
        temp->left = r;
        temp->right = l;
        if(l != nullptr) invertTree(l);
        if(r != nullptr) invertTree(r);
        return temp;
    }
};
