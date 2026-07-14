class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()==1) return true;
        string res;
        for(char c:s){
            c = tolower((unsigned char)c);

            if(c>='a'&&c<='z'||c<='9'&&c>='0'){
                res+=c;
            }
        }
        char* start = &res[0];
        char* end = &res[res.length()-1];
        while(start<end){
            if(*start!=*end)return false;
            if(*start==*end){
                start++;
                end--;
                continue;
            }
        }
        return true;
    }
};
