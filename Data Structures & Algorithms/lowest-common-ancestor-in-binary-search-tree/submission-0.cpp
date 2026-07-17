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
    unordered_map<TreeNode* , int> phash;
    bool pfound = false;
    bool foundq = false;
    TreeNode* ans = nullptr;
    void findP(TreeNode* root, TreeNode* p){
        if(root == nullptr) return;
        if(root == p) pfound = true;
        if(pfound){
            phash[root] = 1;
            return;
        }
        if(!pfound) findP(root->left,p);
        if(!pfound) findP(root->right,p);
        if(pfound){
            phash[root] = 1;
            return;
        }

    }
    TreeNode* findCommon(TreeNode* root,unordered_map<TreeNode*,int> hash , TreeNode* q){
        if(root == nullptr) return nullptr;
        if(root == q) foundq = true;
        if(ans!= nullptr) return ans;
        
        if(!foundq) findCommon(root->left,hash,q);
        if(!foundq) findCommon(root->right,hash,q);
        
        if(foundq && ans==nullptr){
            if(hash[root]>=1)  ans = root;
        }
        return ans;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findP(root,p);
        findCommon(root,phash,q);
        return ans;

    }
};
