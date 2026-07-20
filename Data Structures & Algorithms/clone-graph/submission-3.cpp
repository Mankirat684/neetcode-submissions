/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& vis) {
        if(vis.count(node)){
            return vis[node];
        }
        Node* copy = new Node(node->val);
        vis[node] = copy;
        for(auto it:node->neighbors){
            copy->neighbors.push_back(dfs(it,vis));
        }
        
        return copy;
    }
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<Node*, Node*> vis;
        Node* ans = dfs(node, vis);
        
        return ans;
    }
};
