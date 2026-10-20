class WordDictionary {
private:
    struct TreeNode{
       TreeNode* children[26]{}; 
       bool isEnd = false; 
    };
    TreeNode* root; 
public:
    WordDictionary() {
        root = new TreeNode();
    }
    
    void addWord(string word) {
        TreeNode* temp = root;
        for(char ch : word){
            int n = ch - 'a'; 
            if(!temp->children[n]){
                temp->children[n] = new TreeNode();
            }
            temp = temp->children[n];
        }
        temp->isEnd = true;
    }
    
    bool searchSub(TreeNode* node, string& word, int index){
        if(index == word.size()) return node->isEnd; 
        if(word[index] == '.'){
            for(TreeNode* cnode : node->children){
                if(cnode){
                    if(searchSub(cnode, word, index+1)) return true; 
                }
            }
            return false;
        }
        char ch = word[index];
        int n = ch - 'a';
        if(!node->children[n]) return false;
        return searchSub(node->children[n], word, index+1); 
    }
    bool search(string word) {
        TreeNode* temp = root; 
        return searchSub(temp, word, 0);
    }
};
