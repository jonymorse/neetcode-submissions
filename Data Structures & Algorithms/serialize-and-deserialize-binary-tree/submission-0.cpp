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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string out;
        sdfs(root, out);
        return out;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return ddfs(data, i);
    }

private:
    void sdfs(TreeNode* root, string& out){
        if(!root){
            out += ("N,");
            return;
        }
        out += (to_string(root->val));
        out += (",");
        sdfs(root->left, out);
        sdfs(root->right, out); 
    }
    TreeNode* ddfs(string& data, int& i){
        string st;
        while(i < data.size() && data[i] != ','){
            st+= data[i]; 
            i++; 
        }
        i++;
        if(st == "N") return nullptr;
        TreeNode* root = new TreeNode(stoi(st));
        root->left = ddfs(data, i);
        root->right = ddfs(data, i); 
        return root;

    }
};
