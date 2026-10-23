class Solution {
public:
    int countSubstrings(string s) {
         int n = s.size();
        int a = 0,b=0;
        int ans=0;
        int ansL = 0;
        for(int i = 0; i < n; i++ ){
            int l = i,r=i;
            while(l>=0 && r<n){
                if(s[l]!=s[r]) break;
                ans++;
                r++;
                l--; 
            }
            l=i;
            r=i+1;
            while(l>=0 && r<n){
                if(s[l]!=s[r]) break;
                ans++;
                r++;
                l--; 
            }
        }
        
        return ans;
    }
};
