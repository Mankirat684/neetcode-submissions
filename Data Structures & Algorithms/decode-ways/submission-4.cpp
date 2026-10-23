class Solution {
public:
    bool notPossible = false;
    bool canCombine(char n,char m){
        if((n != '1' && n != '2') && m == '0') notPossible = true;
        if(n=='0') return false;
        string s;
        s+= n;
        s+=m;
        int i = stoi(s);
        if(i>=10&&i<=26) return true;
        return false;
    }

    int ways(vector<int>& dp, int i, string& s){
        if(dp[i]!= -1) return dp[i];
        if(notPossible) return 0;
        bool check = canCombine(s[i-1],s[i]);
        if(!check && s[i] == '0') notPossible = true; 
        if(check && s[i]!= '0') dp[i] = ways(dp,i-1,s)+ways(dp,i-2,s);
        else if(check && s[i] == '0') dp[i] = ways(dp,i-2,s);
        else dp[i] = ways(dp,i-1,s);
        return dp[i];
    }

    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int size = s.size();
        if(size == 1) return 1;
        vector<int> dp(size,-1);
        dp[0] = 1;
        bool check = canCombine(s[0],s[1]);
        if(check && s[1] != '0') dp[1] = 2;
        else dp[1] = 1;
        ways(dp,size-1,s);
        if(notPossible) return 0;
        return dp[size-1];

    }
};



