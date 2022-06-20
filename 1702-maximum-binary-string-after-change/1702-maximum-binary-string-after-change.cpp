class Solution {
public:
    string maximumBinaryString(string s) {
        int n=s.size();
        if(n==1)
            return s;
        
        int zero=0,prev_one=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='0')
                break;
            else
                prev_one++;
        }
        
        for(int i=0;i<n;i++){
            if(s[i]=='0')
                zero++;
        }
        
        int pos_of_zero =-1;
        
        if(zero>0)
            pos_of_zero=prev_one+zero-1;
        
        string ans="";
        
        for(int i=0;i<n;i++){
            if(i==pos_of_zero)
                ans+="0";
            else
                ans+="1";
        }
        
        return ans;
    }
};