class Solution {
public:
    bool isValid(string s) {
        if(s.size()<2) return false;
        stack <char> s1;
        for(char c:s){
            if(c=='(' || c=='[' || c=='{'){
                s1.push(c);
            }else if(c == ')'){
                if(s1.empty()) return false;
                if(s1.top()=='(')s1.pop();
                else return false;
            }else if(c == ']'){
                if(s1.empty()) return false;
                if(s1.top()=='['){
                     s1.pop();
                }
                else return false;
                
            }else if(c == '}'){
                if(s1.empty()) return false;
                if(s1.top()=='{')s1.pop();
                else return false;
            }


        }
        if(s1.empty()) return true;
        else return false;
        
    }
};
