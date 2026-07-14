class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size()==0)return 0;
        unordered_map<char,int> freq;
        int left=0;
        int ans = 1;
        int maxFreq=0;
        int tempAns=1;
        int validReplacements=0;
        for(int right = 0;right<s.size();right++){
           freq[s[right]]++;
           maxFreq=max(freq[s[right]],maxFreq);
           while(right-left+1-maxFreq>k){
                freq[s[left]]--;
                left++;
           }
           ans=max(ans,right-left+1);
        }

        return ans;
    }
};
