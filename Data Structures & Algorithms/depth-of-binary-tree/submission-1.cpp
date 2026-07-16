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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int ans=0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(q.size()>0){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == nullptr){
                ans++;
                if(!q.empty()){
                    q.push(nullptr);
                    continue;
                }else{
                    break;
                }
            }
            if(curr->left!=nullptr){
                q.push(curr->left);
            }
            if(curr->right!=nullptr){
                q.push(curr->right);
            }
            
        }
        return ans;
    }
    // TreeNode* dfs(TreeNode*root){
    //     if(root == nullptr){
    //         currMax = max(currMax,tempMax);
    //         return nullptr;
    //     }    
    //     TreeNode* left = dfs(root->left);
    //     TreeNode* right = dfs(root->right);
    //     return root;
    // }
};
