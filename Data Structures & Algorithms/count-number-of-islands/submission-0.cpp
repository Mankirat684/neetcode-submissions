        // for(int i = m;i<row;i++){
        //     for(int j = n; j<col; j++ ){
class Solution {
   public:
    void dfs(vector<vector<char>>& grid, int& m, int& n, vector<vector<bool>>& vis) {
        vis[m][n] = true;
        int row = grid.size();
        int col = grid[0].size();
        int i = m;
        int j = n;
         if (i > 0) {
                int t = i - 1;
                if (vis[t][j] != true && grid[t][j] == '1') dfs(grid, t, j, vis);  // above
                
            }
            if (j > 0) {
                int t = j - 1;
                if (vis[i][t] != true && grid[i][t] == '1')dfs(grid, i, t, vis);  // left
            }
            if (j < col - 1) {
                int t = j + 1;
                if (vis[i][t] != true && grid[i][t] == '1')dfs(grid, i, t, vis);  // right
            }
            if (i < row - 1) {
                int t = i + 1;
                if (vis[t][j] != true && grid[t][j] == '1')dfs(grid, t, j, vis);  // down
            }
        //     }
        // }
    }

    
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        int ct = 0;
        for (int i = 0;i<row;i++){
            for(int j= 0 ; j<col;j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    ct++;
                    dfs(grid,i,j,vis);
                }
            }
        }
        return ct;
    }
};
