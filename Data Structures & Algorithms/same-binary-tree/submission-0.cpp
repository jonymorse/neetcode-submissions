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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool s = true;
        return dfs(p,q,s);
    }
private: 
    int dfs(TreeNode* p, TreeNode* q, bool& s){
        if(p == nullptr && q == nullptr) return 1;
        if(p == nullptr && q != nullptr) return 0;
        if(p != nullptr && q == nullptr) return 0;
        if(p->val != q->val) return 0;
        int l = dfs(p->left, q->left, s);
        int r = dfs(p->right, q->right, s);        
        return l && r;

    }
};
