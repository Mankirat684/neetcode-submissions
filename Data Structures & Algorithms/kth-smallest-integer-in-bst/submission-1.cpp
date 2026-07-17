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
    int counter=0;
    int ans = -1;
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr) return 0;
        if(ans!=-1) return ans;
        kthSmallest(root->left,k);
        counter++;
        if(k==counter){
            ans = root->val;
            return ans;
        }
        kthSmallest(root->right,k);
        return ans;
    }
};
