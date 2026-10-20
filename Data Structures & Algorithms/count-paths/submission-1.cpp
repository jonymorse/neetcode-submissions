class Solution {
public:
    int ROWS, COLS;
    vector<vector<int>> memo; 
    int uniquePaths(int m, int n) {
        memo.resize(m, vector<int>(n, -1));
        ROWS = m;
        COLS = n;
        return dfs(0,0); 
    }
private:
    int dfs(int r, int c){
        if(r < 0 || r == ROWS || c < 0 || c == COLS){
            return 0; 
        }
        if(r == ROWS - 1 && c == COLS -1){
            return 1; 
        }
        if(memo[r][c] > -1) return memo[r][c]; 
        int down = 0;
        int right = 0; 
        down += dfs(r+1, c);
        right += dfs(r, c+1); 

        return memo[r][c] = down+right;


    }
};
