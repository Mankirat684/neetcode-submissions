class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(string s:strs){
            int size = s.size();
            encoded+= to_string(size)+'#'+s;
        }
        return encoded;
    }
    int findL(int &curr,string s){
        string temp = "";
        while(s[curr]!='#'){
            temp += s[curr];
            curr++;
        }
        int num = stoi(temp);
        if(num!=0) curr++;
        return num;

    }
    vector<string> decode(string s) {
        vector<string> ans;
        int curr = 0;
        if(s.size()<1){
            
            return ans;
        }
        int firstSearchIndex = findL(curr,s);
        while(curr<s.size()){
            string temp = "";
            int i=0;
            while(i<firstSearchIndex){
                temp += s[curr];
                curr++;
                i++;
            }
            if(firstSearchIndex==0) curr++;
            ans.push_back(temp);
            if(curr<s.size()) firstSearchIndex = findL(curr,s);
        }
        return ans;

    }
};
