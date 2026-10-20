class Solution {
private:
    unordered_map<int, bool> memo; 
    struct Trie{
        Trie* children[26]; 
        bool isEnd = false; 
    };

    void insertTrie(Trie* root, string& s){
        Trie* curr = root; 
        for(char c : s){
            if(curr->children[c - 'a'] == nullptr){
                curr->children[c - 'a'] = new Trie();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(Trie* root, string& s, int index){
        if(index == s.size()) return true; 
        if(memo.contains(index)) return memo[index]; 

        Trie* curr = root; 
        for(int i = index; i < s.size(); i++){
            int nums = s[i] - 'a';
            memo[i] = false; 
            if(!curr->children[nums]) break; 
            curr = curr->children[nums]; 

            if(curr->isEnd){
                if(search(root, s, i+1)) return memo[index] = true; 
            }
        }

        return memo[index] = false; 
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        Trie* trie = new Trie(); 
        for(string& word : wordDict){
            insertTrie(trie, word); 
        }

        return search(trie, s, 0);
    }
};
