class Solution {
public:
    vector<vector<int>> adjList(int n,vector<vector<int>>& e){
        vector<vector<int>> l(n);
        for(int i = 0;i<e.size();i++){
            l[e[i][0]].push_back(e[i][1]);
            l[e[i][1]].push_back(e[i][0]);
        }
        return l;
    }
    int dfs(int i,vector<vector<int>>&adj , vector<int> &vis){
        if(vis[i]==1) return 0;
        vis[i] = 1;
        for(auto it:adj[i]){
            if(vis[it]!=1){
                dfs(it,adj,vis);
            }
        }
        return 1;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj = adjList(n,edges);
        int ctr = 0;
        vector<int> vis(n,0);
        for(int i = 0;i<adj.size();i++){
            ctr += dfs(i,adj,vis);
        }
        return ctr;
    }
};
