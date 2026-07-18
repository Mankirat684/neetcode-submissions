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
    unordered_map<int,int>hash_i,hash_p;
    TreeNode* helper(vector<int>& preorder,int pl , int pr , vector<int>inorder , int il, int ir){
        if(pl>pr||il>ir) return nullptr;
        if(hash_i.empty()){
            for(int i = 0;i<inorder.size();i++){
                hash_i[inorder[i]]=i;
            }
        }
        if(hash_p.empty()){
            for(int i = 0;i<inorder.size();i++){
                hash_p[preorder[i]]=i;
            }
        }
        
        TreeNode* root = new TreeNode(preorder[pl]);

        int modIn = hash_i[root->val];
        int ls = modIn - il;
        

        root->left = helper(
            preorder,
            pl+1,
            pl+ls,
            inorder,
            il,
            modIn-1
        );
        root->right = helper(
            preorder,
            pl+ls+1,
            pr,
            inorder,
            modIn+1,
            ir
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        TreeNode* root = helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        return root;
        
    }
    // int divideInorder(vector<int> &arr,int &n){
    //     int index = -1;
    //     for(int i=0;i<arr.size();i++){
    //         if(arr[i]==n){
    //             index = i;
    //         } 
    //     }
    //     return index;
    // }

    // vector<vector<int>> dividePreorder(vector<int> &arr,vector<int>l,vector<int>r){
    //     vector<int> left,right;
    //     unordered_map<int,int>hl,hr;
    //     for(char c : l){
    //         hl[c]++;
    //     }
    //     for(char c : r){
    //         hr[c]++;
    //     }
    //     for(int i = 0;i<arr.size();i++){
    //         if(hl[arr[i]]==1) left.push_back(arr[i]);
    //         if(hr[arr[i]]==1) right.push_back(arr[i]);
    //     }
    //     vector<vector<int>> div;
    //     div.push_back(left);
    //     div.push_back(right);
    //     return div;
    // }
    
};
