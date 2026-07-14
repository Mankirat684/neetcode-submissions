class Solution {
public:
    bool isAnagram(string s, string t) {
        char hash_1[26] = {0};
        char hash_2[26] = {0};
        for(char ch: s){
            hash_1[ch- 'a']++;
        }
        for(char ch: t){
            hash_2[ch- 'a']++;
        }
       for(int i=0;i<26;i++){
        if(hash_1[i]!=hash_2[i]) return false;
       }
       return true;
    }
};
