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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        if p and q are in different subtrees then the split is the lca
        if p is lower or q is lower in the subtree then either p or q is the lca
        */
        if(!root) return root;
        if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p,q);
        }
        else if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p,q);
        }
        return root;
    }
};
