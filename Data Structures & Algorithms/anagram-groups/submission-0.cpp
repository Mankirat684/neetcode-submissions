class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>> hashStr;
       for(string s : strs){
         int freq[26]={0};
         for(char c : s){
            freq[c-'a']++;
         }
        string key; 
        for(auto c:freq){
            key += '#'+to_string(c);
        }
        hashStr[key].push_back(s);
        }
        vector<vector<string>> result;
        for(auto it : hashStr){
            result.push_back(it.second);
        }
       
        return result;



    }
};