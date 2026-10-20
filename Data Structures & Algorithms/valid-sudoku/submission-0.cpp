class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i < rows; i++){
            unordered_set<char> rowCheck;
            for(int j = 0; j < cols; j++){

                if(board[i][j] == '.'){
                    continue;
                }
                if(rowCheck.find(board[i][j]) != rowCheck.end()){
                    return false;
                }
                rowCheck.insert(board[i][j]);
            }
        }
        for(int j = 0; j < cols; j++){
            unordered_set<char> colCheck;
            for(int i = 0; i < rows; i++){
                
                if(board[i][j] == '.'){
                    continue;
                }
                if(colCheck.find(board[i][j]) != colCheck.end()){
                    return false;
                }
                colCheck.insert(board[i][j]);
            }
        }

        for(int square = 0; square < board.size(); square++){
            unordered_set<char> seen;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    int row = (square / 3 ) * 3 + i;
                    int col = (square % 3 ) * 3 + j;

                    if(board[row][col] == '.'){
                        continue;
                    }
                    if( seen.find(board[row][col]) != seen.end() ){
                        return false;
                    }
                    seen.insert(board[row][col]);

                }
            }       
        }

    return true;
    }
};
