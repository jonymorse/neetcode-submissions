class Solution {
public:
    int ROWS, COLS; 
    struct Trie{
        Trie* children[26];
        bool isEnd = false;
        int index;
        Trie() {
            for(int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };
    Trie* trie;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res; 
        ROWS = board.size();
        COLS = board[0].size(); 
        trie = new Trie();
        Trie* temp; 
        for(int i = 0; i < words.size(); i++){
            string w = words[i]; 
            temp = trie;
            add(temp, w, 0, i);
        }
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                temp = trie; 
                char l = board[i][j]; 
                int n = l - 'a'; 
                if(temp->children[n]){
                    search(board, temp->children[n], i, j, res, words);
                }
            }
        }
        return res; 
    }
private:
    void add(Trie* temp, string& word, int i, int index){
        if(i == word.size()){
            temp->isEnd = true;
            temp->index = index; 
            return;
        }
        char ch = word[i]; 
        int n = ch - 'a'; 
        if(!temp->children[n]){
            temp->children[n] = new Trie(); 
        }
        add(temp->children[n], word, i+1, index);
    }
    void search(vector<vector<char>>& board, Trie* temp, int row, int col, vector<string>& res, vector<string>& words){
        if(temp->isEnd){
            res.push_back(words[temp->index]);
            temp->isEnd = false;
        };

        
        int x[4] = {-1,1,0,0};
        int y[4] = {0,0,-1,1};
        for(int i = 0 ; i < 4; i++){
            int rx = row + x[i]; 
            int cy = col + y[i];
            bool isSafe = rx >= 0 && rx < ROWS && cy >= 0 && cy < COLS;
            if(isSafe){
                char ch = board[rx][cy]; 
                int n = ch - 'a'; 
                char c = board[row][col];

                if(temp->children[n] && ch != '#'){
                    board[row][col] = '#'; 
                    search(board, temp->children[n], rx, cy, res, words); 
                }
                board[row][col] = c; 
            }
        }
        return; 
        
    }
};
