class Solution {
   public:
    unordered_map<string, int> hash;
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> sizes;
        for (string w : wordDict){
            hash[w] = 1;
            sizes.push_back(w.size());
        } 
        int n = s.size();
        vector<bool> dp(n + 1, false);  // state is ith position which can be formed.
        dp[n] = true;
        for (int i = n - 1; i >= 0; i--) {
            for (int size : sizes) {
                if(i+size>n) continue;
                string t = s.substr(i, size);
                if (hash.count(t)) {
                    if (dp[i + t.size()] == true){
                        dp[i] = true;
                        break;
                    }
                        
                    else
                        dp[i] = false;
                } else
                    dp[i] = false;
            }
        }
        return dp[0];
    }
};
