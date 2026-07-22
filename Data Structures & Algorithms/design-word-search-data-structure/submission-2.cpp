class TrieNode {
   public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class WordDictionary {
   public:
    TrieNode* root;
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        int size = word.size();
        TrieNode* curr = root;
        for (int i = 0; i < size; i++) {
            if (curr->children[word[i] - 'a'] == nullptr) {
                TrieNode* temp = new TrieNode();
                curr->children[word[i] - 'a'] = temp;
            }
            curr = curr->children[word[i] - 'a'];
        }
        curr->isEnd = true;
    }
    int wordl = 0;
    void dfs(TrieNode* curr, string word, int j, bool& ans) {
        int s = word.size();
        if (curr == nullptr) return;
        if (ans) return;
        if (j == s) {
            if (curr->isEnd) {
                ans = true;
                return;
            }
            ans = false;
            return;
        }

        if (word[j] != '.') dfs(curr->children[word[j] - 'a'], word, j + 1, ans);
        if (word[j] == '.') {
            for (int i = 0; i < 26; i++) {
                dfs(curr->children[i], word, j + 1, ans);
            }
        }
        return;
    }
    bool search(string word) {
        TrieNode* curr = root;
        bool ans = false;
        dfs(curr, word, 0, ans);
        return ans;
    }
};

// for(int i = j;i<word.size();i++){
//     if(word[i] != '.' && curr->children[word[i]-'a'] == nullptr){
//         return;
//     };
//     if(word[i] == '.'){
//         if(i == word.size()-1){
//             ans=true;
//             return;
//         }
//         for(int m=0;m<26;m++){
//             dfs(curr->children[m],word,i+1,ans);
//         }
//         if(ans == false) return;
//     }else curr = curr->children[word[i]-'a'];

// }
// if(curr->isEnd) ans = true;
