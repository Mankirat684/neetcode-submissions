class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        int ans=1;
        int left=0;
        int right = 1;
        vector<int> freq(256,0);
        freq[s[left]]=1;
        int sizeS = s.size();
        while(right<sizeS){
           freq[s[right]]++;
           while(freq[s[right]]>1){
            freq[s[left]]--;
            left++;
           }
           ans=max(ans,right-left+1);
           right++;
        }
        return ans;
    }
};
















// left=right-1;
//             right=left+1;
//             if(s[left]==s[right]){
//                 left=right;
//                 right=left+1;
//             }
//             for(int i=0;i<256;i++){
//                 freq[i]=0;
//             }
//             freq[s[left]]=1;
//             ans=max(ans,tempAns);
//             tempAns=1;



            // if(s[right]!=prev){
            //     prev=s[right];
            //     right++;
            //     tempAns++;
            // }else{
                
            //     prev=s[right];
            //     left=right;
            //     //right++;
            //     tempAns=0;
            // }
            //     ans=max(tempAns,ans);