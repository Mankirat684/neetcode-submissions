class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        if(tokens.size()<3) return stoi(tokens[0]);
        for(string c:tokens){
            if(c != "+" && c != "-" && c != "*" && c != "/"){
                st.push(c);
            }else if(c == "+"){
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                st.push(to_string(a+b));
            }else if(c == "-"){
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                st.push(to_string(b-a));
            }else if(c == "*"){
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                st.push(to_string(a*b));
            }else if(c == "/"){
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                st.push(to_string(b/a));
            }
        }
        return stoi(st.top());
        
    }
};