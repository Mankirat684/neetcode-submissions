class Solution {
public:
    bool hasCycle = false;
    vector<vector<int>> adjList(int n,vector<vector<int>>& prerequisites){
        vector<vector<int>> l(n);
        for(auto it:prerequisites){
            l[it[1]].push_back(it[0]);
        }
        return l;
    }

    void dfs(int i,vector<vector<int>>& adj,vector<int>& vis,vector<int>& pathVis,stack<int>& st){
        if(hasCycle) return;
        if(vis[i]==1) return;
        vis[i] = 1;
        pathVis[i] = 1;

        for(auto it:adj[i]){
            if(vis[it]!=1){
                dfs(it,adj,vis,pathVis,st);
            }else if(pathVis[it]==1){
                hasCycle = true;
                return;
            }
        }
        st.push(i);
        pathVis[i] = 0;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist = adjList(numCourses,prerequisites);
        vector<int> vis(numCourses,0),pathVis(numCourses,0);

        stack<int> st;    

        for(int i = 0; i<numCourses ; i++){
            dfs(i,adjlist,vis,pathVis,st);
        }
        if(hasCycle) return false;
        vector<int> topo;
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        
        if(topo.size()==numCourses) return true;
        return false;
    }
};
