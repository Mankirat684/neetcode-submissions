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
    Node* dfs(Node* node, Node* copy, unordered_map<Node*, Node*>& vis) {
        
        for (auto it : node->neighbors) {
            if (vis.count(it)) {
                copy->neighbors.push_back(vis[it]);
                continue;
            }
            Node* temp = new Node(it->val);
            vis[node] = copy;
            copy->neighbors.push_back(temp);
            dfs(it, temp, vis);
        }
        return copy;
    }
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<Node*, Node*> vis;
        Node* ans = new Node(node->val);
        dfs(node, ans, vis);
        return ans;
    }
};
