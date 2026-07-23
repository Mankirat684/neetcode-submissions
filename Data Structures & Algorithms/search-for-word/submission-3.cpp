class Solution {
   public:
    bool canForm = false;
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    vector<vector<int>> choice(vector<vector<char>>& board, string word) {
        char c = word[0];
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == c) ans.push_back({i, j});
            }
        }
        return ans;
    }

    void dfs(int curr, vector<int> ids, vector<vector<char>>& board, string word,vector<vector<bool>>& vis) {
        if(vis[ids[0]][ids[1]]) return;
        vis[ids[0]][ids[1]] = true;

        int rows = board.size();
        int cols = board[0].size();

        if (canForm) return;
        if (curr == word.size()) {
            canForm = true;
            return;
        }

        for (int k = 0; k < 4; k++) {
            int r = ids[0], c = ids[1];
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
            if (word[curr] != board[nr][nc]) continue;
            
            
            if(!vis[nr][nc]) dfs(curr+1, {nr, nc}, board, word,vis); 
            
        }
        vis[ids[0]][ids[1]] = false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> choices = choice(board, word);
        
        int c = 1;
        for (int i = 0; i < choices.size(); i++) {
            vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));
            if (!canForm) dfs(c, choices[i], board, word,vis);
        }

        return canForm;
    }
};
