class Solution {
public:
    string minWindow(string s, string t) {
        string ans;
        if(t.size()>s.size())return ans;
        unordered_map<char,int> freq_t;
        unordered_map<char,int> freq_win;
        int keyCount_t=0;
        int keyCount_win=0;
        for(char c:t){
            freq_t[c]++;
            if(freq_t[c]==1){
                keyCount_t++;
            }
        }
        int required = freq_t.size();
        int formed=0;
        int left =0;
        int minLength = 100001;
        int minLeft=0;
        int minRight=0;
        for(int right=0;right<s.size();right++){
            bool isValid = true;
            freq_win[s[right]]++;
            if(freq_t.count(s[right])&&freq_win[s[right]]==freq_t[s[right]]){
                formed++;
            }

            if(formed==required){
                while(freq_t[s[left]]<freq_win[s[left]]){
                    freq_win[s[left]]--;
                    left++;
                }
            
                if(minLength>right-left+1){
                minLength=right-left+1;
                minLeft = left;
                minRight = right;
              }
            
            }
        }
        for(int i=minLeft;i<=minRight;i++){
            ans+=s[i];
        }
        if(minLength == 100001) return "";
        return ans;

    }
};
