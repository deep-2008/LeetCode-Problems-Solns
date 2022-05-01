class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st,tt;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='#' && st.empty()){
                //st.pop();
                continue;
            }
            
            if(s[i]=='#' ){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        
        for(int i=0;i<t.size();i++){
            if(t[i]=='#' && tt.empty()){
                //tt.pop();
                continue;
            }
            
            if(t[i]=='#' ){
                tt.pop();
                continue;
            }
            tt.push(t[i]);
        }
        
        if(tt.empty() && st.empty())
            return true;
        
        if(st.size() != tt.size())
            return false;
        
        while(!st.empty() && !tt.empty()){
            if(st.top() != tt.top())
                return false;
            st.pop();
            tt.pop();
            
        }
        return true;
    }
};