class TrieNode {
   public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class PrefixTree {
   public:
    TrieNode* root;
    PrefixTree() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->children[word[i] - 'a'] == nullptr) {
                TrieNode* temp = new TrieNode();
                curr->children[word[i] - 'a'] = temp;
            }
            curr = curr->children[word[i] - 'a'];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->children[word[i] - 'a'] == nullptr) return false;
            curr = curr->children[word[i] - 'a'];
        }
        if (curr->isEnd) return true;
        return false;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (curr->children[prefix[i] - 'a'] == nullptr) return false;
            curr = curr->children[prefix[i] - 'a'];
        }
        return true;
    }
};

class Solution {
   public:
    void traversal(vector<vector<char>>& board, string s, int r, int c, TrieNode* curr,
                   vector<string>& ans, vector<vector<bool>>& vis) {
        vis[r][c] = true; // to check whether we should even consider this cell

        int tr = board.size();
        int tc = board[0].size();


        if (curr->children[board[r][c]-'a'] == nullptr) {
            vis[r][c] = false;
            return;
        }

        s += board[r][c];
        if(curr->children[board[r][c]-'a']->isEnd) {
            ans.push_back(s);
            curr->children[board[r][c]-'a']->isEnd = false;
        }

        if (r < tr - 1) {
            int t = r + 1;
            if (!vis[t][c]) traversal(board, s, t, c, curr->children[board[r][c]-'a'], ans, vis);
        }
        if (r > 0) {
            int t = r - 1;
            if (!vis[t][c]) traversal(board, s, t, c, curr->children[board[r][c]-'a'], ans, vis);
        }
        if (c < tc - 1) {
            int t = c + 1;
            if (!vis[r][t]) traversal(board, s, r, t, curr->children[board[r][c] - 'a'], ans, vis);
        }
        if (c > 0) {
            int t = c - 1;
            if (!vis[r][t]) traversal(board, s, r, t, curr->children[board[r][c] - 'a'], ans, vis);
        }
        vis[r][c] = false;

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || board[0].empty()) return {};
        PrefixTree* trie = new PrefixTree();
        string temp = "";

        int row = board.size();
        int col = board[0].size();
        vector<string> ans;

        for (string s : words) {
            trie->insert(s);
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                vector<vector<bool>> vis(row, vector<bool>(col, false));
                traversal(board, temp, i, j, trie->root, ans, vis);
            }
        }

        return ans;
    }
};
