class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int a = 0,b=0;
        string ans;
        int ansL = 0;
        for(int i = 0; i < n; i++ ){
            int l = i,r=i;
            while(l>=0 && r<n){
                if(s[l]!=s[r]) break;
                if(r-l+1 > ansL){
                    a=l;
                    b=r;
                    ansL = r-l+1;
                }
                r++;
                l--; 
            }
            l=i;
            r=i+1;
            while(l>=0 && r<n){
                if(s[l]!=s[r]) break;
                if(r-l+1 > ansL){
                    a=l;
                    b=r;
                    ansL = r-l+1;
                }
                r++;
                l--; 
            }
        }
        for(int i = a;i<=b;i++) ans += s[i];
        return ans;
    }
};
