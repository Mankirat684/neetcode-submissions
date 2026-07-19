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

class Codec {
   public:
    // Encodes a tree to a single string.

    string encode = "";
    void dfs(TreeNode* root) {
        if (!root) {
            encode += "n#";
            return;
        }

        encode += to_string(root->val) + "#";
        dfs(root->left);
        dfs(root->right);
    }

    string serialize(TreeNode* root) {
        encode = "";
        dfs(root);
        return encode;
    }
    pair<optional<int>, int> readNode(string& s,int &i) {
        if (s.empty()) {
            return {nullopt, 0};
        }
        string f = "";
        pair<optional<int>, int> final;
        while (i < s.size() && s[i] != '#') {
            if (s[i] == 'n') {
                final.first = nullopt;
                //s.erase(0, i + 2);
                final.second = i+2;
                i=i+2;
                return final;
            };
            f += s[i];
            i++;
        }
        final.first = stoi(f);
        //s.erase(0, i + 1);
        final.second = i+1;
        i=i+1;
        return final;
    }

    TreeNode* helper(string& data,int &idx) {
        pair<optional<int>, int> currPair = readNode(data,idx);
        if (currPair.first == nullopt) return nullptr;
        TreeNode* curr = new TreeNode((currPair.first).value_or(-11111));
        curr->left = helper(data,idx);
        curr->right = helper(data,idx);
        return curr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        TreeNode* curr = helper(data,idx);
        return curr;
    }
};
