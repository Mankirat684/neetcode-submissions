class Solution {
   public:
   bool hasCycle = false;
    vector<vector<int>> adjList(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> l(n);
        for (auto it : prerequisites) {
            l[it[0]].push_back(it[1]);
            l[it[1]].push_back(it[0]);
        }
        return l;
    }
    void dfs(int m , int p , vector<vector<int>>& adj,vector<int> &vis  ){
        if(hasCycle) return ;
        if(!vis[m]) vis[m] = 1;
        for(auto it:adj[m]){
            if(vis[it]!=1){
                dfs(it,m,adj,vis);
            } else {
                if(p != it) hasCycle = true; 
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<int> vis(n,0);
        vector<vector<int>> adj = adjList(n,
        edges);
        dfs(0,-1,adj,vis);
        if(hasCycle) return false;
        for(int i:vis){
            if(i==0) return false;
        }
        return true;
    }
};
