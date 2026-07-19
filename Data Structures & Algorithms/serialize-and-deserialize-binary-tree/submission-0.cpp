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
    pair<optional<int>, string> readNode(string& s) {
        if (s.empty()) {
            return {nullopt, ""};
        }
        string f = "";
        int i = 0;
        pair<optional<int>, string> final;
        while (i < s.size() && s[i] != '#') {
            if (s[i] == 'n') {
                final.first = nullopt;
                s.erase(0, i + 2);
                final.second = s;
                return final;
            };
            f += s[i];
            i++;
        }
        final.first = stoi(f);
        s.erase(0, i + 1);
        final.second = s;
        return final;
    }

    TreeNode* helper(string& data) {
        pair<optional<int>, string> currPair = readNode(data);
        if (currPair.first == nullopt) return nullptr;
        TreeNode* curr = new TreeNode((currPair.first).value_or(-11111));
        curr->left = helper(data);
        curr->right = helper(data);
        return curr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* curr = helper(data);
        return curr;
    }
};
