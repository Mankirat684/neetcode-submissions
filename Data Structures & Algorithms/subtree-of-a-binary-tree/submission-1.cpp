/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void traversal(vector<optional<int>> &arr,TreeNode* root){
        if(root == nullptr){
            arr.push_back(nullopt);
            return ;
        }
        arr.push_back(root->val);
        traversal(arr,root->left);
        traversal(arr,root->right);
        
    }
bool compare(vector<optional<int>>& m,vector<optional<int>>& n) {

    if (n.size() > m.size()) return false;

    for (int i = 0; i <= m.size() - n.size(); i++) {

        bool ok = true;

        for (int j = 0; j < n.size(); j++) {

            if (m[i + j] != n[j]) {
                ok = false;
                break;
            }
        }

        if (ok) return true;
    }

    return false;
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<optional<int>> main,sub;
        traversal(main,root);
        traversal(sub,subRoot);
        bool ans = compare(main,sub);
        return ans;
    }
};
