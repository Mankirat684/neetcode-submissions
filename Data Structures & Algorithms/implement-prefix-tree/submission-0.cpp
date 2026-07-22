class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(int i = 0;i<word.size();i++){
            if(curr->children[word[i]-'a']==nullptr){
                TrieNode* temp = new TrieNode();
                curr->children[word[i]-'a'] = temp;
            }
            curr = curr->children[word[i]-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i = 0;i<word.size();i++){
            if(curr->children[word[i]-'a'] == nullptr) return false;
            curr = curr->children[word[i]-'a'];
        }
        if(curr->isEnd) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i = 0;i<prefix.size();i++){
            if(curr->children[prefix[i]-'a'] == nullptr) return false;
            curr = curr->children[prefix[i]-'a'];
        }
        return true;
    }
};
