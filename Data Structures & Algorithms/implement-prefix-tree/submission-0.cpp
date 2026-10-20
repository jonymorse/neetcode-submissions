class PrefixTree {
private:
    struct Tree{
        char letter; 
       Tree* children[26];
       bool isEnd = false; 
    };
    Tree* root;
public:
    PrefixTree() {
        root = new Tree();
    }
    
    void insert(string word) {
        Tree* temp = root; 
        
        for(char i : word){
            int c = i - 'a'; 
            if(temp->children[c]){
                temp = temp->children[c]; 
                continue;
            }
            Tree* node = new Tree(c); 
            temp->children[c] = node; 
            temp = temp->children[c];             
        }
        temp->isEnd = true; 
    }
    
    bool search(string word) {
        Tree* temp = root; 
        for(char i : word){
            int c = i - 'a';
            if(!temp->children[c]) return false; 
            temp = temp->children[c]; 
        }
        if(!temp->isEnd) return false; 
        return true; 
    }
    
    bool startsWith(string prefix) {
        Tree* temp = root; 
        for(char i : prefix){
            int c = i - 'a';
            if(!temp->children[c]) return false; 
            temp = temp->children[c]; 
        }
        return true;     }
};
