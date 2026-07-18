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
        // vector<int> ret;
        // ret.push_back(maxS);
        // ret.push_back(sum2);
        // ret.push_back(sum3);
        // ret.push_back(p);

class Solution {
public:
    int maxi = INT_MIN;
    int calcSum(int m,int n,int p){
        int sum2=n+p,sum3=m+p,sum4 = m+n+p;
        int maxS = max(max(sum2,p),sum3);
        return maxS;
    }
    int helper(TreeNode* root){
        if(root == nullptr) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        int sum = calcSum(left,right,root->val);
        maxi = max(max(maxi,sum),(left+right+root->val));
        return sum;
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxi;
    }
};
