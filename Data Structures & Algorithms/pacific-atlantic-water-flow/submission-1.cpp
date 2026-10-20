class Solution {
public:
    vector<vector<bool>> pacific;
    vector<vector<bool>> atlantic; 
    int ROWS;
    int COLS; 
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        pacific.assign(ROWS, vector<bool>(COLS,false));
        atlantic.assign(ROWS, vector<bool>(COLS,false)); 

        vector<vector<int>> res; 

        for(int i = 0; i < ROWS; i++) dfs(heights, i, 0, pacific);
        for(int i = 1; i < COLS; i++) dfs(heights, 0, i, pacific);
        for(int i = 0; i < ROWS-1; i++) dfs(heights, i, COLS-1, atlantic);
        for(int i = 0; i < COLS; i++) dfs(heights, ROWS-1, i, atlantic);

        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res; 
    }
private:

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& reach){
        if(reach[r][c]) return;
        reach[r][c] = true;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            bool safe = nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS;
            if(safe && heights[nr][nc] >= heights[r][c]){
                dfs(heights, nr, nc, reach);
            }
        }
    return;
    }
};
