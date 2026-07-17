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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        vector<int> temp;
        ans.push_back(temp);
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == nullptr){
                if(!q.empty()){
                    vector <int> temp;
                    ans.push_back(temp);
                    q.push(nullptr);
                    continue;
                }else{
                    break;
                }
            }
            ans[ans.size()-1].push_back(curr->val);
            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right!=nullptr) q.push(curr->right);
        }
        return ans;
    }
};
