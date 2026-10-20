class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ex = false;
        int rows = board.size();
        int cols = board[0].size();
        int index = 0; 
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == word[index]){
                    vector<vector<char>> b = board;
                    dfs(b, i, j, rows, cols, word, index, ex);
                    if(ex) return true; 
                }
            }
        }
        return false;
    }
private:
    void dfs(vector<vector<char>> board, int row, int col, int& rows, int& cols, string& word, int index, bool& ex){
        if(board[row][col] != word[index]){
            board[row][col] = '0'; 
            return;
        }
        
        if(board[row][col] == word[index]){
            index++;
            board[row][col] == '0';
            if(index == word.length()){
                ex = true; 
                return;
            }
        }
        board[row][col] = '0'; 
        if(row - 1 >= 0 && board[row-1][col] != '0') dfs(board, row-1, col, rows, cols, word, index, ex);
        if(row + 1 < rows && board[row+1][col] != '0') dfs(board, row+1, col, rows, cols, word, index, ex);
        if(col - 1 >= 0 && board[row][col-1] != '0') dfs(board, row, col-1, rows, cols, word, index, ex);
        if(col + 1 < cols && board[row][col+1] != '0') dfs(board, row, col+1, rows, cols, word, index, ex);

        return;
    }
};
