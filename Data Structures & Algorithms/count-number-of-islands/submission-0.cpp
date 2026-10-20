class Solution {
public:
    int rows, cols;
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int count = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count; 
    }
    void dfs(vector<vector<char>>& grid, int row, int col){
        if(grid[row][col] == '0') return; 
        grid[row][col] = '0';
        
        if(row-1 >= 0) dfs(grid, row-1,col);
        if(row+1 < rows) dfs(grid, row+1, col);
        if(col-1 >= 0) dfs(grid, row, col-1);
        if(col+1 < cols) dfs(grid, row, col+1);
        return;
    }
};
