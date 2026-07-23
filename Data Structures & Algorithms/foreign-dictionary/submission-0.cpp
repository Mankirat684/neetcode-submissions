class Solution {
   public:
    bool invalid = false;
    unordered_map<char, int> hash;
    void makeEdge(char a, char b, vector<vector<int>>& adj) { adj[a - 'a'].push_back(b - 'a'); }
    void build(string& s1, string& s2, vector<vector<int>>& adj) {
        for (int i = 0; i < s1.size(); i++) {
            if (i < s2.size()) {
                if (s1[i] == s2[i]) {
                    hash[s1[i]] = 1;
                    continue;
                }
                makeEdge(s1[i], s2[i], adj);
                hash[s1[i]] = 1;
                hash[s2[i]] = 1;
                return;
            } else {
                invalid = true;
            }
        }
    }
    void checkCycle(int i, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        if (invalid) return;
        if (vis[i] == 1) return;
        vis[i] = 1;
        pathVis[i] = 1;

        for (auto it : adj[i]) {
            if (vis[it] != 1) {
                checkCycle(it, adj, vis, pathVis);
            } else if (pathVis[it] == 1) {
                invalid = true;
                return;
            }
        }
        pathVis[i] = 0;
    }

    void dfs(int i, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
        vis[i] = 1;
        for (auto it : adj[i]) {
            if (!vis[it]) dfs(it, adj, vis, st);
        }
        st.push(i);
    }

    string foreignDictionary(vector<string>& words) {
        for (auto& word : words)
            for (char c : word) hash[c] = 1;
        vector<vector<int>> adj(26);
        vector<int> vis(26, 0);
        vector<int> vis_n(26, 0);
        vector<int> p_vis(26, 0);
        stack<int> st;
        for (int i = 0; i < words.size() - 1; i++) {
            build(words[i], words[i + 1], adj);
        }
        for (int i = 0; i < 26; i++) {
            if (!vis[i]) {
                checkCycle(i, adj, vis, p_vis);
            }
        }
        string ans = "";
        if (invalid) return ans;
        for (int i = 0; i < 26; i++) {
            if (hash[i + 'a'] != 1) continue;
            if (!vis_n[i]) {
                dfs(i, adj, vis_n, st);
            }
        }
        while (!st.empty()) {
            ans += (st.top() + 'a');
            st.pop();
        }
        
        return ans;
    }
};
