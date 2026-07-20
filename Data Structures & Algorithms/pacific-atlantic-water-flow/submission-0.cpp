class Solution {
   public:
    

    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& vis) {
        int row = heights.size();
        int col = heights[0].size();
        vis[i][j] = true;
        if (i > 0) {
            int t = i - 1;
            if (vis[t][j] != true && heights[t][j] >= heights[i][j])
                dfs(heights, t, j, vis);  // above
        }
        if (j > 0) {
            int t = j - 1;
            if (vis[i][t] != true && heights[i][t] >= heights[i][j])
                dfs(heights, i, t, vis);  // left
        }
        if (j < col - 1) {
            int t = j + 1;
            if (vis[i][t] != true && heights[i][t] >= heights[i][j])
                dfs(heights, i, t, vis);  // right
        }
        if (i < row - 1) {
            int t = i + 1;
            if (vis[t][j] != true && heights[t][j] >= heights[i][j])
                dfs(heights, t, j, vis);  // down
        }
    }

    vector<vector<bool>> canReachPacific(vector<vector<int>>& heights) {

        int row = heights.size();
        int col = heights[0].size();
        vector<vector<bool>> pacific(row, vector<bool>(col, false));
        for (int i = 0; i < col; i++) {
            dfs(heights, 0, i, pacific);
        }
        for (int i = 0; i < row; i++) {
            dfs(heights, i, 0, pacific);
        }
        return pacific;
    }

    vector<vector<bool>> canReachAtlantic(vector<vector<int>>& heights) {

        int row = heights.size();
        int col = heights[0].size();
        vector<vector<bool>> atlantic(row, vector<bool>(col, false));
        for (int i = 0; i < col; i++) {
            dfs(heights, row-1, i, atlantic);
        }
        for (int i = 0; i < row; i++) {
            dfs(heights, i, col-1, atlantic);
        }
        return atlantic;
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific = canReachPacific(heights);
        vector<vector<bool>> atlantic = canReachAtlantic(heights);
        vector<vector<int>> ans;
        int row = heights.size();
        int col = heights[0].size();

        for(int i = 0; i<row;i++){
            for(int j = 0; j<col; j++){
                if(pacific[i][j]==true&&pacific[i][j] == atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
