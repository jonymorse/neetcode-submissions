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


// preorder = [1,2,3,4]
// inorder = [2,1,3,4]

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, preorder[0]);
    }

private:
    int preIndex = 0;
    int inIndex = 0;
    TreeNode* dfs(vector<int>& preorder, vector<int>&inorder, int limit){
        if(preIndex >= preorder.size()) return nullptr;
        if(inorder[inIndex] == limit && inorder[inIndex] != preorder[preIndex]){
            inIndex++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preIndex]);
        preIndex++;
        root->left = dfs(preorder,inorder, root->val);
        root->right = dfs(preorder,inorder, limit);
        return root;
    }


};
