class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        
        if(n==2)
            return "11";
        
        string s="11";
        
        for(int i=3;i<n+1;i++){
            string t="";
            s=s+'&';
            int c=1;
            
            for(int j=1;j<s.size();j++){
                if(s[j]==s[j-1])
                    c++;
                
                else{
                    t=t+to_string(c);
                    t=t+s[j-1];
                    c=1;
                }
            }
            s=t;
        }
        
        return s;
    }
};