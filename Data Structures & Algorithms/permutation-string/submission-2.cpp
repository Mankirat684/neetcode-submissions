class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<1||s2.size()<s1.size())return false;
        int sizeSmaller = s1.size();
        int found = 0;
        unordered_map<char,int> hash;
        for(char c:s1){
            hash[c]++;
        }   
        pair<int,int> ansWindow = {0,sizeSmaller-1};
        while(ansWindow.second<s2.size()&&found<sizeSmaller){
            unordered_map<char,int> temp;
            
            for(int i = ansWindow.first;i<=ansWindow.second;i++){
                temp[s2[i]]++;
            }            
            if(temp==hash) return true;
            ansWindow.first++;
            ansWindow.second++;        
        }
        return false;
    }
};











            // if(hash.find(s2[ansWindow.second])!=hash.end()){
            //    // char erased=s2[ansWindow.second];
            //    found++;
            //     hash.erase(s2[ansWindow.second]);
            //     ansWindow.second++;
            //     if(hash.empty()){
            //         return true;
            //     }
            // }else{
            //     for(char c:s1){
            //         if( hash.find(c) == hash.end() ) hash[c]=1;
            //     }
            //     found=0;
            //     ansWindow.first = ansWindow.second-1;
            //     ansWindow.second++;
            // }